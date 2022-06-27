/**
 * @file    singly-linked-list-queue.c
 * @brief   A file for linked list queue (SLLQ) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with sllq_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singly-linked-list-queue.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief   CREATES an SLLQ by initialising struct components
 * @return  A pointer to the address of the newly created & initalised SLLQ
*/
sllq_list_t* 
sllq_init(int cmp(void*, void*)) {
    
    // Create space for the list in the heap
    sllq_list_t *new_sllq;
    new_sllq = (sllq_list_t *)malloc(sizeof(sllq_list_t));
    assert(new_sllq != NULL);

    // Assign the function pointer
    new_sllq->cmp = cmp;

    // Initialise parameters & return list address
    new_sllq->head = new_sllq->tail = (sllq_list_t *)NULL;
    return new_sllq;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the SLLQ by removing the list, it's nodes & data from
 *              the heap
 * @param[out]  sllq     A pointer to the address of the SLLQ to be deleted
*/
void 
sllq_free(sllq_list_t *sllq) {

    // Temporary nodes to traverse the SLLQ
    sllq_node_t *current_node = sllq->head;
    sllq_node_t *next_node;

    // Traverse the SLLQ from the start & free contents from the heap
    while (current_node != NULL) {
        next_node = current_node->next;
        if (current_node->key != NULL) {
            free(current_node->key);
        }
        free(current_node);
        current_node = next_node;
    }
    // Free the list from the heap
    free(sllq);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS an integer flag if the SLLQ has no nodes
 * @param[in]   sllq     A pointer to the SLLQ whose length needs to be checked
 * @return      0 if SLLQ has ZERO nodes
 *              1 if SLLQ has at least ONE node
*/
int 
sllq_is_empty(sllq_list_t *sllq) {
    assert(sllq != NULL);
    return ((sllq->head == NULL) && (sllq->tail == NULL));
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new node at the TAIL (i.e. END) of the SLLQ
 * @param[out]  sllq         The linked list queue to recieve a new node
 * @param[in]   new_data    The data to be added as part of the new node
 * @return      A pointer to the address of the new added SLLQ node or NULL
*/
sllq_node_t* 
sllq_enqueue(sllq_list_t *sllq, void *new_data) {
    
    sllq_node_t *new_tail;
    new_tail = (sllq_node_t *)malloc(sizeof(sllq_node_t));
    assert(new_tail != NULL);
    new_tail->key = new_data;
    new_tail->next = (sllq_node_t *)NULL;

    // CASE 1: Linked list queue is EMPTY
    if (sllq->tail == NULL) {
        sllq->head = sllq->tail = new_tail;

    // CASE 2: Linked list queue has at LEAST 1 node
    } else {
        sllq->tail->next = new_tail;
        sllq->tail = new_tail;
    }
    return sllq->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       REMOVES the HEAD (i.e FIRST) node of the SLLQ
 * @param[out]  sllq     The linked list queue to have the head node deleted
 * @return      The new HEAD node of the SLLQ
*/
sllq_node_t* 
sllq_dequeue(sllq_list_t *sllq) {

    sllq_node_t *old_head, *tmp;
    assert((sllq != NULL) && (sllq->head != NULL));
    old_head = sllq->head;
    sllq->head = sllq->head->next;

    // EXCEPTION: 1 node in the LLQ remains
    if (sllq->tail == NULL) {
        sllq->tail = (sllq_node_t *)NULL;
    }
    free(old_head);
    return sllq->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the HEAD (i.e. FIRST) node in the SLLQ
 * @param[in]   sllq     The SLLQ with the desired HEAD node
 * @return      A pointer to the FIRST node of the SLLQ
*/
sllq_node_t *sllq_get_head(sllq_list_t *sllq) {
    assert((sllq != NULL) && (sllq->head != NULL));
    return sllq->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the TAIL (i.e. LAST) node in the SLLQ
 * @param[in]   sllq     The SLLQ with the desired TAIL node
 * @return      A pointer to the LAST node of the SLLQ
*/
sllq_node_t* 
sllq_get_tail(sllq_list_t *sllq) {
    assert((sllq != NULL) && (sllq->tail != NULL));
    return sllq->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       SEARCHES & returns a node that matches the target search data
 * @param[in]   sllq             The SLLQ whose data content needs searching
 * @param[in]   cmp_fn          A POINTER FUNCTION allow comparison of 
 *                              different data types
 * @param[in]   target_data     Target search data that might be in the SLLQ
 * @return      A pointer to the node that matches the target search data, OR
 *              A sllq_node_t NULL value to indicate that no matches were found
*/
sllq_node_t* 
sllq_iterative_search(sllq_list_t *sllq, void *target_data) {

    sllq_node_t *current_node;
    current_node = sllq->head;

    // Linear search the SLLQ up to the TAIL node
    while (current_node->next != NULL) {

        /* Assumed return values for cmp_fn:
            -1  current_node->data is LESS THAN target_data
             0  current_node->data is EQUAL TO target_data
             1  current_node->data is GREATER THAN to target_data
        */
        if (sllq->cmp(current_node->key, target_data) == CMP_FN_EQUAL) {
            return current_node;
        }
        current_node = current_node->next;
    }
    // No matches detected
    return (sllq_node_t *)NULL;
}

/* -------------------------------------------------------------------------- */