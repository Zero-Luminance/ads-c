/**
 * @file    singly-linked-list-queue.h
 * @brief   A header file for linked list queue (SLLQ) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with sllq_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#define EMPTY_LIST 0
#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a SLLQ
 * @param   key     Pointer to the DATA associated with the SLLQ node
 * @param   next    Pointer to the next NODE in the SLLQ
*/
typedef struct sllq_node_t {
    void                *key;
    struct sllq_node_t  *next;
} sllq_node_t;

/**
 * @brief   A mechanism to interace with the SLLQ
 * @param   head    Node at the START of the SLLQ
 * @param   tail    Node at the END of the SLLQ
 * @param   cmp     Function pointer to COMPARE keys in each node:
 *                  -1 1st argument is LESS than 2nd argument
 *                   0 1st & 2nd arguments are EQUAL
 *                   1 ast argument is GREATER than 2nd argument
*/
typedef struct sllq_list_t {
    sllq_node_t         *head;
    sllq_node_t         *tail;
    int                 (*cmp)(void*, void*);
} sllq_list_t;

/* -------------------------------------------------------------------------- */

// SLLQ Operations:
sllq_list_t *sllq_init(int cmp(void*, void*));
void sllq_free(sllq_list_t *sllq);
int sllq_is_empty(sllq_list_t *sllq);

sllq_node_t *sllq_enqueue(sllq_list_t *sllq, void *new_data);
sllq_node_t *sllq_dequeue(sllq_list_t *sllq);

sllq_node_t *sllq_get_head(sllq_list_t *sllq);
sllq_node_t *sllq_get_tail(sllq_list_t *sllq);

sllq_node_t *sllq_iterative_search(sllq_list_t *sllq, void *target_data);

/* -------------------------------------------------------------------------- */