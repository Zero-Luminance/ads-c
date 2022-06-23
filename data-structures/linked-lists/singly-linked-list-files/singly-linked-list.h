/**
 * @file    singly-linked-list.h
 * @brief   A HEADER file for singly linked list (SLL) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with sll_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#define EMPTY_LIST 0
#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

// Connecting these creates a SLL:
typedef struct sll_node_t {
    void                *data;      /* Replace 'void' with desired data type */
    struct sll_node_t   *next;      /* The address of the next SLL node */
} sll_node_t;

// Keeping track of SLL data:
typedef struct sll_list_t {
    sll_node_t          *head;      /* Node at the START of the SLL */
    sll_node_t          *tail;      /* Node at the END of the SLL */
} sll_list_t;

/* -------------------------------------------------------------------------- */

// SLL Operations:
sll_list_t *sll_init(void);
void sll_free(sll_list_t *sll);
int sll_is_empty(sll_list_t *sll);

sll_list_t *sll_insert_head(sll_list_t *sll, void *new_data);
sll_list_t *sll_insert_tail(sll_list_t *sll, void *new_data);

sll_list_t *sll_delete_head(sll_list_t *sll);
sll_list_t *sll_delete_tail(sll_list_t *sll);

sll_node_t *sll_get_head(sll_list_t *sll);
sll_node_t *sll_get_tail(sll_list_t *sll);
sll_node_t *sll_node_search(sll_list_t *sll, int (*cmp_fn)(void*, void*), void *target_data);

sll_node_t *sll_recursive_reverse(sll_list_t *sll, sll_node_t *first);
void sll_iterative_reverse(sll_list_t *sll);

/* -------------------------------------------------------------------------- */