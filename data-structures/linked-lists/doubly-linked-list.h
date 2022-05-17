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

#define EMPTY_LIST 0
#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

// Connecting these creates a DLL:
typedef struct dll_node_t {
    void                *data;      /* Replace 'void' with desired data type */
    struct dll_node_t   *next;      /* The address of the next DLL node */
    struct dll_node_t   *prev;      /* The address of the previous DLL node */
} dll_node_t;

// Keeping track of DLL data:
typedef struct dll_list_t {
    dll_node_t          *head;      /* Node at the START of the SDLL */
    dll_node_t          *tail;      /* Node at the END of the DLL */
    unsigned int        length;     /* Number of DLL nodes */
} dll_list_t;

/* -------------------------------------------------------------------------- */

// DLL Operations:
dll_list_t *dll_init(void);
void dll_free(dll_list_t *dll);
int dll_is_empty(dll_list_t *dll);

dll_list_t *dll_insert_head(dll_list_t *dll, void *new_data);
dll_list_t *dll_insert_tail(dll_list_t *dll, void *new_data);

dll_list_t *dll_delete_head(dll_list_t *dll);
dll_list_t *dll_delete_tail(dll_list_t *dll);

dll_node_t *dll_get_head(dll_list_t *dll);
dll_node_t *dll_get_tail(dll_list_t *dll);
dll_node_t *dll_node_search(dll_list_t *dll, int (*cmp_fn)(void*, void*), void *target_data);

void dll_reverse(dll_list_t *dll);

/* -------------------------------------------------------------------------- */