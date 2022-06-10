/**
 * @file    linked-list-queue.c
 * @brief   A file for linked list queue (LLQ) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with llq_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list-queue.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief   CREATES an LLQ by initialising struct components
 * @return  A pointer to the address of the newly created & initalised LLQ
*/
llq_list_t* 
llq_init(void) {
    
    // Create space for the list in the heap
    llq_list_t *new_llq;
    new_llq = (llq_list_t *)malloc(sizeof(llq_list_t));
    assert(new_llq != NULL);

    // Initialise parameters & return list address
    new_llq->head = new_llq->tail = (llq_list_t *)NULL;
    new_llq->length = EMPTY_LIST;
    return new_llq;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the LLQ by removing the list, it's nodes & data from
 *              the heap
 * @param[out]  llq     A pointer to the address of the LLQ to be deleted
*/
void 
llq_free(llq_list_t *llq) {

    // Temporary nodes to traverse the LLQ
    llq_node_t *current_node = llq->head;
    llq_node_t *next_node;

    // Traverse the LLQ from the start & free contents from the heap
    while (current_node != NULL) {
        next_node = current_node->next;
        if (current_node->data != NULL) {
            free(current_node->data);
        }
        free(current_node);
        current_node = next_node;
        llq->length--;
    }
    // Free the list from the heap
    free(llq);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS an integer flag if the LLQ has no nodes
 * @param[in]   llq     A pointer to the LLQ whose length needs to be checked
 * @return      0 if LLQ has ZERO nodes
 *              1 if LLQ has at least ONE node
*/
int 
llq_is_empty(llq_list_t *llq) {
    assert(llq != NULL);
    return (llq->length == EMPTY_LIST);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new node at the TAIL (i.e. END) of the LLQ
 * @param[out]  llq         The linked list queue to recieve a new node
 * @param[in]   new_data    The data to be added as part of the new node
 * @return      A pointer to the address of the new added LLQ node or NULL
*/
llq_node_t* 
llq_enqueue(llq_list_t *llq, void *new_data) {
    
    llq_node_t *new_tail;
    new_tail = (llq_node_t *)malloc(sizeof(llq_node_t));
    assert(new_tail != NULL);
    new_tail->data = new_data;
    new_tail->next = (llq_node_t *)NULL;

    // CASE 1: Linked list queue is EMPTY
    if (llq->tail == NULL) {
        llq->head = llq->tail = new_tail;

    // CASE 2: Linked list queue has at LEAST 1 node
    } else {
        llq->tail->next = new_tail;
        llq->tail = new_tail;
    }
    llq->length++;
    return llq->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       REMOVES the HEAD (i.e FIRST) node of the LLQ
 * @param[out]  llq     The linked list queue to have the head node deleted
 * @return      The new HEAD node of the LLQ
*/
llq_node_t* 
llq_dequeue(llq_list_t *llq) {

    llq_node_t *old_head, *tmp;
    assert((llq != NULL) && (llq->head != NULL));
    old_head = llq->head;
    llq->head = llq->head->next;

    // EXCEPTION: 1 node in the LLQ remains
    if (llq->tail == NULL) {
        llq->tail = (llq_node_t *)NULL;
    }
    free(old_head);
    llq->length--;
    return llq->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the HEAD (i.e. FIRST) node in the LLQ
 * @param[in]   llq     The LLQ with the desired HEAD node
 * @return      A pointer to the FIRST node of the LLQ
*/
llq_node_t *llq_get_head(llq_list_t *llq) {
    assert((llq != NULL) && (llq->head != NULL));
    return llq->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the TAIL (i.e. LAST) node in the LLQ
 * @param[in]   llq     The LLQ with the desired TAIL node
 * @return      A pointer to the LAST node of the LLQ
*/
llq_node_t* 
llq_get_tail(llq_list_t *llq) {
    assert((llq != NULL) && (llq->tail != NULL));
    return llq->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       SEARCHES & returns a node that matches the target search data
 * @param[in]   llq             The LLQ whose data content needs searching
 * @param[in]   cmp_fn          A POINTER FUNCTION allow comparison of 
 *                              different data types
 * @param[in]   target_data     Target search data that might be in the LLQ
 * @return      A pointer to the node that matches the target search data, OR
 *              A llq_node_t NULL value to indicate that no matches were found
*/
llq_node_t* 
llq_node_search(llq_list_t *llq, int (*cmp_fn)(void*, void*), void *target_data) {

    llq_node_t *current_node;
    current_node = llq->head;

    // Linear search the LLQ up to the TAIL node
    while (current_node->next != NULL) {

        /* Assumed return values for cmp_fn:
            -1  current_node->data is LESS THAN target_data
             0  current_node->data is EQUAL TO target_data
             1  current_node->data is GREATER THAN to target_data
        */
        if (cmp_fn(current_node->data, target_data) == CMP_FN_EQUAL) {
            return current_node;
        }
        current_node = current_node->next;
    }
    // No matches detected
    return (llq_node_t *)NULL;
}

/* -------------------------------------------------------------------------- */