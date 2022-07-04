/**
 * @file    singly-linked-list-stack.h
 * @brief   A header file for linked list stack (SLLS) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with slls_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a SLLS
 * @param   key     Pointer to the DATA associated with the SLLS node
 * @param   next    Pointer to the next NODE in the SLLS
*/
typedef struct slls_node_t {
    void                *key;
    struct slls_node_t  *next;
} slls_node_t;

/**
 * @brief   A mechanism to interace with the SLLS
 * @param   head    Node at the START of the SLLS
 * @param   tail    Node at the END of the SLLS
 * @param   cmp     Function pointer to COMPARE keys in each node:
 *                  -1 1st argument is LESS than 2nd argument
 *                   0 1st & 2nd arguments are EQUAL
 *                   1 ast argument is GREATER than 2nd argument
*/
typedef struct slls_list_t {
    slls_node_t         *head;
    slls_node_t         *tail;
    int                 (*cmp)(void*, void*);
} slls_list_t;

/* -------------------------------------------------------------------------- */

// SLLS Operations:
slls_list_t *slls_init(int cmp(void*, void*));
void slls_free(slls_list_t *slls);
int slls_is_empty(slls_list_t *slls);

slls_node_t *slls_push(slls_list_t *slls, void *new_data);
slls_node_t *slls_pop(slls_list_t *slls);

slls_node_t *slls_get_head(slls_list_t *slls);
slls_node_t *slls_get_tail(slls_list_t *slls);

slls_node_t *slls_iterative_search(slls_list_t *slls, void *target_data);

/* -------------------------------------------------------------------------- */