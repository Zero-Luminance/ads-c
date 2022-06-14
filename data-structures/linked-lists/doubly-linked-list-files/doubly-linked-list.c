/**
 * @file    doubly-linked-list.c
 * @brief   A file for doubly linked list (DLL) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with dll_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly-linked-list.h"

/* -------------------------------------------------------------------------- */

/**
 * @brief   CREATES an DLL by initialising struct components
 * @return  A pointer to the address of the newly created & initalised DLL
*/
dll_list_t* 
dll_init(void) {

    // Create space for the list on the heap;
    dll_list_t *new_dll;
    new_dll = (dll_list_t *)malloc(sizeof(dll_list_t));
    assert(new_dll != NULL);

    // Initialise parameters & return list address
    new_dll->head = new_dll->tail = (dll_node_t *)NULL;
    return new_dll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the DLL by removing the list, it's nodes & data from
 *              the heap
 * @param[out]  dll     A pointer to the address of the DLL to be deleted
*/
void 
dll_free(dll_list_t *dll) {

    // Temporary nodes to traverse DLL
    assert(dll != NULL);
    dll_node_t *current_node = dll->head; 
    dll_node_t *next_node;

    // Traverse the DLL from the start & free contents from the heap
    while (current_node != NULL) {
        next_node = current_node->next;
        if (current_node->data != NULL) {
            free(current_node->data);
        }
        free(current_node);
        current_node = next_node;
    }
    // Free the list from the heap
    free(dll);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       Returns an integer flag if the DLL has no nodes
 * @param[in]   dll     A pointer to the DLL whose length needs to be checked
 * @return      1 if DLL has ZERO nodes
 *              0 if DLL has at least ONE node
*/
int 
dll_is_empty(dll_list_t *dll) {
    assert(dll != NULL);
    return ((dll->head == NULL) && (dll->tail == NULL));
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new TAIL (i.e. FIRST) node in the DLL
 * @param[out]  dll         A pointer to the address of the DLL to have 
 *                          new node
 * @param[in]   new_data    The address of the new data to be inserted as 
 *                          part of the DLL
 * @return      A pointer to the DLL with a newly added HEAD node
 * @note        Replace 'void' with desired data type
*/
dll_list_t* 
dll_insert_head(dll_list_t *dll, void *new_data) {

    dll_node_t *new_head;
    new_head = (dll_node_t *)malloc(sizeof(dll_node_t));
    assert((dll != NULL) && (new_head != NULL));
    new_head->data = new_data;
    new_head->next = dll->head;
    new_head->prev = (dll_node_t *)NULL;

    // EXCEPTION: This is the 1st node insertion in the DLL
    if (dll_is_empty(dll)) {
        dll->tail = new_head;

    } else {
        dll->head->prev = new_head;
    }
    dll->head = new_head;
    return dll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       INSERTS a new TAIL (i.e. END) node in the DLL
 * @param[out]  dll         A pointer to the address of the DLL to have 
 *                          new node
 * @param[in]   new_data    The address of the new data to be inserted as 
 *                          part of the DLL
 * @return      A pointer to the DLL with a newly added TAIL node
 * @note        Replace 'void' with desired data type
*/
dll_list_t* 
dll_insert_tail(dll_list_t *dll, void *new_data) {

    dll_node_t *new_tail;
    new_tail = (dll_node_t *)malloc(sizeof(dll_node_t));
    assert((dll != NULL) && (new_tail != NULL));
    new_tail->data = new_data;
    new_tail->next = (dll_node_t *)NULL;
    new_tail->prev = dll->tail;

    // EXCEPTION: This is the 1st node insertion in the DLL
    if (dll->tail == NULL) {
        dll->head = dll->tail = new_tail;

    } else {
        dll->tail->next = new_tail;
        dll->tail = new_tail;
    }
    return dll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the HEAD (i.e. FIRST) node of the DLL
 * @param[out]  dll     The DLL whose HEAD node needs to be deleted
 * @return      A pointer to the updated DLL
*/
dll_list_t* 
dll_delete_head(dll_list_t *dll) {

    dll_node_t *old_head;
    assert((dll != NULL) && (dll->head != NULL));
    old_head = dll->head;
    dll->head = dll->head->next;

    // EXCEPTION: The only DLL node got deleted
    if (dll->head == NULL) {
        dll->tail = (dll_node_t *)NULL;

    } else {
        dll->head->prev = NULL;
    }
    free(old_head);
    return dll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       DELETES the TAIL (i.e. END) node of the DLL
 * @param[out]  dll     The DLL whose TAIL node needs to be deleted
 * @return      A pointer to the updated DLL
*/
dll_list_t* 
dll_delete_tail(dll_list_t *dll) {

    dll_node_t *old_foot;
    assert((dll != NULL) && (dll->tail));
    old_foot = dll->tail;
    dll->tail = dll->tail->prev;
    
    // EXCEPTION: The only DLL node deleted
    if (dll->tail == NULL) {
        dll->head = (dll_node_t *)NULL;

    } else {
        dll->tail->next = (dll_node_t *)NULL;
    }
    free(old_foot);
    return dll;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief
*/
dll_node_t* 
dll_get_head(dll_list_t *dll) {
    assert((dll != NULL) && (dll->head != NULL));
    return dll->head;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RETURNS the HEAD (i.e. FIRST) node in the DLL
 * @param[in]   dll     The DLL with the desired HEAD node
 * @return      A pointer to the FIRST node of the DLL
*/
dll_node_t* 
dll_get_tail(dll_list_t *dll) {
    assert((dll != NULL) && (dll->tail != NULL));
    return dll->tail;
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
dll_node_t* 
dll_node_search(dll_list_t *dll, int (*cmp_fn)(void*, void*), void *target_data) {

    dll_node_t *current_node;
    current_node = dll->head;

    // Linear search the DLL up to the TAIL node
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
    return (dll_node_t *)NULL;
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       RECURSIVELY reverses the node ORDER in a DLL
 * @param[out]  dll     The DLL whose nodes order is to be reversed
 * @param[in]   first   The 1st node in the input SLL; ALWAYS pass
 *                      input as 'dll->head'
 * @note        Call function as: dll_recursive_reverse(dll, dll->head)
*/
void dll_recursive_reverse(dll_list_t *dll, dll_node_t *first) {

    // EXCEPTION: DLL is EMPTY
    if (first == NULL) return;

    // BASE CASE: Reached the TAIL node of the DLL
    if (first->next == NULL) {
        dll->tail = dll->head;
        dll->head = first;
        return;
    }
    /* RECURSIVE CASE: Keep traversing the DLL while adjusting the .next &
                       .prev pointers until we have reached the TAIL node */
    dll_node_t *next_node = first->next;
    first->next = first->prev;
    first->prev = next_node;
    dll_recursive_reverse(dll, first->prev);
}

/* -------------------------------------------------------------------------- */

/**
 * @brief       ITERATIVELY reverses the node ORDER in a DLL
 * @param[out]  dll     The DLL whose nodes order is to be reversed
*/
void 
dll_iterative_reverse(dll_list_t *dll) {
    
    dll_node_t *curr, *next;
    curr = dll->head;
    dll->head = dll->tail;
    dll->tail = curr;

    // Iterate all the way until the TAIL (i.e. LAST) DLL node
    while (curr != NULL) {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }
}

/* -------------------------------------------------------------------------- */