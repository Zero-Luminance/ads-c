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

#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a SLL
 * @param   key     Pointer to the DATA associated with the SLL node
 * @param   next    Pointer to the next NODE in the SLL
*/
typedef struct sll_node_t {
    void                *key;
    struct sll_node_t   *next;
} sll_node_t;

/**
 * @brief   A mechanism to interace with the SLL
 * @param   head    Node at the START of the SLL
 * @param   tail    Node at the END of the SLL
 * @param   cmp     Function pointer to COMPARE keys in each node:
 *                  -1 1st argument is LESS than 2nd argument
 *                   0 1st & 2nd arguments are EQUAL
 *                   1 ast argument is GREATER than 2nd argument
*/
typedef struct sll_list_t {
    sll_node_t          *head;
    sll_node_t          *tail;
    int                 (*cmp)(void*, void*);
} sll_list_t;

/* -------------------------------------------------------------------------- */

// SLL Operations:
sll_list_t *sll_init(int cmp(void*, void*));
void sll_free(sll_list_t *sll);
int sll_is_empty(sll_list_t *sll);

sll_list_t *sll_insert_head(sll_list_t *sll, void *new_key);
sll_list_t *sll_insert_tail(sll_list_t *sll, void *new_key);

sll_list_t *sll_delete_head(sll_list_t *sll);
sll_list_t *sll_delete_tail(sll_list_t *sll);

sll_node_t *sll_get_head(sll_list_t *sll);
sll_node_t *sll_get_tail(sll_list_t *sll);

sll_node_t *sll_iterative_search(sll_list_t *sll, void *target_key);

sll_node_t *sll_recursive_reverse(sll_list_t *sll, sll_node_t *first);
void sll_iterative_reverse(sll_list_t *sll);

/* -------------------------------------------------------------------------- */