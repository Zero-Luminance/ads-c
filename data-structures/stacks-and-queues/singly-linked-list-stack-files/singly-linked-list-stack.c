/**
 * @file    singly-linked-list-stack.c
 * @brief   A file for linked list stack (SLLS) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with slls_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singly-linked-list-stack.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief   CREATES an SLLS by initialising struct components
 * @return  A pointer to the address of the newly created & initalised SLLS
*/
slls_list_t *slls_init(int cmp(void*, void*)) {

    // Create space for the list in the heap
    slls_list_t *new_slls;
    new_slls = (slls_list_t *)malloc(sizeof(slls_list_t));
    assert(new_slls != NULL);

    // Assign the function pointer
    new_slls->cmp = cmp;

    // Initialise parameters & return list address
    new_slls->head = new_slls->tail = (slls_list_t *)NULL;
    return new_slls;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the SLLS by removing the list, it's nodes & data from
 *              the heap
 * @param[out]  slls     A pointer to the address of the SLLS to be deleted
*/
void 
slls_free(slls_list_t *slls) {

    // Temporary nodes to traverse the SLLS
    slls_node_t *current_node = slls->head;
    slls_node_t *next_node;

    // Traverse the SLLS from the start & free contents from the heap
    while (current_node != NULL) {
        next_node = current_node->next;
        if (current_node->key != NULL) {
            free(current_node->key);
        }
        free(current_node);
        current_node = next_node;
    }
    // Free the list from the heap
    free(slls);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS an integer flag if the SLLS has no nodes
 * @param[in]   slls     A pointer to the SLLS whose length needs to be checked
 * @return      0 if SLLS has ZERO nodes
 *              1 if SLLS has at least ONE node
*/
int 
slls_is_empty(slls_list_t *slls) {
    assert(slls != NULL);
    return ((slls->head == NULL) && (slls->tail == NULL));
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new node at the TAIL (i.e. END) of the SLLS
 * @param[out]  slls         The SLLS to recieve a new node
 * @param[in]   new_data    The data to be added as part of the new node
 * @return      A pointer to the address of the new added SLLS node or NULL
*/
slls_node_t* 
slls_push(slls_list_t *slls, void *new_data) {

    slls_node_t *new_tail;
    new_tail = (slls_node_t *)malloc(sizeof(slls_node_t));
    assert(new_tail != NULL);
    new_tail->key = new_data;
    new_tail->next = (slls_node_t *)NULL;

    // CASE 1: Linked list queue is EMPTY
    if (slls->tail == NULL) {
        slls->head = slls->tail = new_tail;

    // CASE 2: Linked list queue has at LEAST 1 node
    } else {
        slls->tail->next = new_tail;
        slls->tail = new_tail;
    }
    return slls->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       REMOVES the TAIL (i.e LAST) node of the SLLS
 * @param[out]  slls     The SLLS to have the head node deleted
 * @return      The new HEAD node of the SLLS
*/
slls_node_t* 
slls_pop(slls_list_t *slls) {

    slls_node_t *old_tail, *tmp;
    assert((slls != NULL) && (slls->tail != NULL));
    tmp = slls->head;
    old_tail = slls->tail;

    // EXCEPTION: Only ONE node is the SLLS remaining
    if (tmp->next == NULL) {
        slls->head = slls->tail = (slls_node_t *)NULL;

    } else {
        // Iterate the 2nd last node
        while (tmp->next != old_tail) {
            tmp = tmp->next;
        }
        tmp->next = (slls_node_t *)NULL;
        slls->tail = tmp;
    }
    free(old_tail);
    return slls;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the HEAD (i.e. FIRST) node in the SLLS
 * @param[in]   slls     The SLLS with the desired HEAD node
 * @return      A pointer to the FIRST node of the SLLS
*/
slls_node_t* 
slls_get_head(slls_list_t *slls) {
    assert(slls->head != NULL);
    return slls->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the TAIL (i.e. LAST) node in the SLLS
 * @param[in]   slls     The SLLS with the desired TAIL node
 * @return      A pointer to the LAST node of the SLLS
*/
slls_node_t* 
slls_get_tail(slls_list_t *slls) {
    assert(slls->tail != NULL);
    return slls->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       SEARCHES & returns a node that matches the target search data
 * @param[in]   slls            The SLLS whose data content needs searching
 * @param[in]   cmp_fn          A POINTER FUNCTION allow comparison of 
 *                              different data types
 * @param[in]   target_data     Target search data that might be in the SLLS
 * @return      A pointer to the node that matches the target search data, OR
 *              A slls_node_t NULL value to indicate that no matches were found
*/
slls_node_t* 
slls_iterative_search(slls_list_t *slls, void *target_data) {

    slls_node_t *current_node;
    current_node = slls->head;

    // Linear search the SLLQ up to the TAIL node
    while (current_node->next != NULL) {

        /* Assumed return values for cmp_fn:
            -1  current_node->data is LESS THAN target_data
             0  current_node->data is EQUAL TO target_data
             1  current_node->data is GREATER THAN to target_data
        */
        if (slls->cmp(current_node->key, target_data) == CMP_FN_EQUAL) {
            return current_node;
        }
        current_node = current_node->next;
    }
    // No matches detected
    return (slls_node_t *)NULL;
}

/* -------------------------------------------------------------------------- */