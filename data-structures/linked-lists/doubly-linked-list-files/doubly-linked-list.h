/**
 * @file    doubly-linked-list.h
 * @brief   A header file for doubly linked list (DLL) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with dll_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a DLL
 * @param   key     Pointer to the DATA associated with the DLL node
 * @param   next    Pointer to the next NODE in the DLL
*/
typedef struct dll_node_t {
    void                *data;
    struct dll_node_t   *next;
    struct dll_node_t   *prev;
} dll_node_t;

/**
 * @brief   A mechanism to interace with the SLL
 * @param   head    Node at the START of the SLL
 * @param   tail    Node at the END of the SLL
 * @param   cmp     Function pointer to COMPARE keys in each node:
 *                  -1 1st argument is LESS than 2nd argument
 *                   0 1st & 2nd arguments are EQUAL
 *                   1 ast argument is GREATER than 2nd argument
*/
typedef struct dll_list_t {
    dll_node_t          *head;
    dll_node_t          *tail;
    int                 (*cmp)(void*, void*);
} dll_list_t;

/* -------------------------------------------------------------------------- */

// DLL Operations:
dll_list_t *dll_init(int cmp(void*, void*));
void dll_free(dll_list_t *dll);
int dll_is_empty(dll_list_t *dll);

dll_list_t *dll_insert_head(dll_list_t *dll, void *new_data);
dll_list_t *dll_insert_tail(dll_list_t *dll, void *new_data);

dll_list_t *dll_delete_head(dll_list_t *dll);
dll_list_t *dll_delete_tail(dll_list_t *dll);

dll_node_t *dll_get_head(dll_list_t *dll);
dll_node_t *dll_get_tail(dll_list_t *dll);

dll_node_t *dll_iterative_search(dll_list_t *dll, void *target_data);

void dll_recursive_reverse(dll_list_t *dll, dll_node_t *first); 
void dll_iterative_reverse(dll_list_t *dll);

/* -------------------------------------------------------------------------- */