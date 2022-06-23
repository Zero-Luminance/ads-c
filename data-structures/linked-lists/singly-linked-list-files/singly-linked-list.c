/**
 * @file    singly-linked-list.c
 * @brief   A file for singly linked list (SLL) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    BEFORE using this file REMEMBER to replace ALL instances of
 *          'void' associated with sll_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singly-linked-list.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief   CREATES an SLL by initialising struct components
 * @return  A pointer to the address of the newly created & initalised SLL
*/
sll_list_t* 
sll_init(void) {

    // Create space for the list on the heap
    sll_list_t *new_sll;
    new_sll = (sll_list_t *)malloc(sizeof(sll_list_t));
    assert(new_sll != NULL);

    // Initialise parameters & return list address
    new_sll->head = new_sll->tail = (sll_node_t *)NULL;
    return new_sll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the SLL by removing the list, it's nodes & data from
 *              the heap
 * @param[out]  sll     A pointer to the address of the SLL to be deleted
*/
void
sll_free(sll_list_t *sll) {

    // Temporary nodes to traverse the SLL
    sll_node_t *current_node = sll->head; 
    sll_node_t *next_node;

    // Traverse the SLL from the start & free contents from the heap
    while (current_node != NULL) {  
        next_node = current_node->next;
        if (current_node->data != NULL) {
            free(current_node->data);
        }
        free(current_node);
        current_node = next_node;
    }

    // Free the list from the heap
    free(sll);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       Returns an integer flag if the SLL has no nodes
 * @param[in]   sll     A pointer to the SLL whose length needs to be checked
 * @return      0 if SLL has ZERO nodes
 *              1 if SLL has at least ONE node
*/
int 
sll_is_empty(sll_list_t *sll) {
    assert(sll != NULL);
    return (sll->length == EMPTY_LIST);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new TAIL (i.e. FIRST) node in the SLL
 * @param[out]  sll         A pointer to the address of the SLL to have 
 *                          new node
 * @param[in]   new_data    The address of the new data to be inserted as 
 *                          part of the SLL
 * @return      A pointer to the SLL with a newly added HEAD node
 * @note        Replace 'void' with desired data type
*/
sll_list_t*
sll_insert_head(sll_list_t *sll, void *new_data) {

    sll_node_t *new_head;
    new_head = (sll_node_t *)malloc(sizeof(sll_node_t));
    assert((sll != NULL) && (new_head != NULL));
    new_head->data = new_data;
    new_head->next = sll->head;
    sll->head = new_head;

    // EXCEPTION: 1st insertion into the SLL
    if (sll->length == EMPTY_LIST) {
        sll->tail = new_head;
    }
    sll->length++;
    return sll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new TAIL (i.e. END) node in the SLL
 * @param[out]  sll         A pointer to the address of the SLL to have 
 *                          new node
 * @param[in]   new_data    The address of the new data to be inserted as 
 *                          part of the SLL
 * @return      A pointer to the SLL with a newly added TAIL node
 * @note        Replace 'void' with desired data type
*/
sll_list_t*
sll_insert_tail(sll_list_t *sll, void *new_data) {

    sll_node_t *new_tail;
    new_tail = (sll_node_t *)malloc(sizeof(sll_node_t));
    assert((sll != NULL) && (new_tail != NULL));
    new_tail->data = new_data;
    new_tail->next = (sll_node_t *)NULL;
    
    // CASE 1: 1st insertion into the SLL
    if (sll->tail == NULL) {
        sll->head = sll->tail = new_tail;

    // CASE 2: Not the 1st insertion into the SLL
    } else {
        sll->tail->next = new_tail;
        sll->tail = new_tail;
    }
    sll->length++;
    return sll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the HEAD (i.e. FIRST) node of the SLL
 * @param[out]  sll     The SLL whose HEAD node needs to be deleted
 * @return      A pointer to the updated SLL
*/
sll_list_t* 
sll_delete_head(sll_list_t *sll) {

    sll_node_t *old_head;
    assert((sll != NULL) && (sll->head != NULL));
    old_head = sll->head;
    sll->head = sll->head->next;
    
    // EXCEPTION: The ONLY node is the SLL is going to be deleted
    if(sll->tail == NULL) {
        sll->tail = (sll_node_t *)NULL;
    }
    free(old_head);
    sll->length--;
    return sll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the TAIL (i.e. END) node of the SLL
 * @param[out]  sll     The SLL whose TAIL node needs to be deleted
 * @return      A pointer to the updated SLL
*/
sll_list_t* 
sll_delete_tail(sll_list_t *sll) {

    sll_node_t *old_tail, *tmp;
    assert((sll != NULL) && (sll->tail != NULL));
    tmp = sll->head;
    old_tail = sll->tail;

    // EXCEPTION: Only ONE node is the SLL remaining
    if (tmp->next == NULL) {
        sll->head = sll->tail = (sll_node_t *)NULL;

    } else {
        // Iterate the 2nd last node
        while (tmp->next != old_tail) {
            tmp = tmp->next;
        }
        tmp->next = (sll_node_t *)NULL;
        sll->tail = tmp;
    }
    free(old_tail);
    sll->length--;
    return sll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the HEAD (i.e. FIRST) node in the SLL
 * @param[in]   sll     The SLL with the desired HEAD node
 * @return      A pointer to the FIRST node of the SLL
*/
sll_node_t*
sll_get_head(sll_list_t *sll) {
    assert((sll != NULL) && (sll->head != NULL));
    return sll->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the TAIL (i.e. LAST) node in the SLL
 * @param[in]   sll     The SLL with the desired TAIL node
 * @return      A pointer to the LAST node of the SLL
*/
sll_node_t*
sll_get_tail(sll_list_t *sll) {
    assert((sll != NULL) && (sll->tail != NULL));
    return sll->tail;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       Searches & returns a node that matches the target search data
 * @param[in]   sll             The SLL whose data content needs searching
 * @param[in]   cmp_fn          A POINTER FUNCTION allow comparison of 
 *                              different data types
 * @param[in]   target_data     Target search data that might be in the SLL
 * @return      A pointer to the node that matches the target search data, OR
 *              A sll_node_t NULL value to indicate that no matches were found
*/
sll_node_t* 
sll_node_search(sll_list_t *sll, int (*cmp_fn)(void*, void*), void *target_data) {

    sll_node_t *current_node;
    current_node = sll->head;

    // Linear search the SLL up to TAIL node
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
    return (sll_node_t *)NULL;
} 

/* -------------------------------------------------------------------------- */

/**
 * @brief       RECURSIVELY reverses the node ORDER in a SLL
 * @param[out]  sll     The SLL whose nodes are to be reversed
 * @param[in]   first   The 1st node in the input SLL; ALWAYS pass
 *                      input as 'sll->head'
 * @note        Call function as: sll_recursive_reverse(sll, sll->head)
 * Credits:     https://stackoverflow.com/questions/14080758/reversing-a-linkedlist-recursively-in-c
*/
sll_node_t* 
sll_recursive_reverse(sll_list_t *sll, sll_node_t *first) {

    // SLL is EMPTY:
    if (first == NULL) return NULL;

    // BASE CASE: Reached the TAIL node of the DLL
    if (first->next == NULL) {
        sll->tail = sll->head;
        sll->head = first;
        return first;
    }
    // RECURSIVE CASE: Keep traversing SLL to TAIL node
    sll_node_t *rest = sll_recursive_reverse(sll, first->next);

    /* NOTES: 
        - Code below this line only executes when base-case returns a value
        - We now traverse the SLL BACKWARDS while adjusting the .next pointers
        - 'rest' will continue to ALWAYS point to the NEW HEAD node
    */
    first->next->next = first;
    first->next = NULL;
    return rest;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       ITERATIVELY reverses the node ORDER in a SLL
 * @param[out]  sll     The SLL whose nodes order is to be reversed
*/
void 
sll_iterative_reverse(sll_list_t *sll) {

    sll_node_t *curr, *prev, *next;
    curr = sll->head;
    sll->head = sll->tail;
    sll->tail = curr;
    prev = (sll_node_t *)NULL;

    // Iterate all the way until the TAIL (i.e. LAST) SLL node
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

/* -------------------------------------------------------------------------- */