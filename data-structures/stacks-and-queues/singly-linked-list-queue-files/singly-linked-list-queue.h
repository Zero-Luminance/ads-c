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

// Connecting these creates a SLLQ:
typedef struct sllq_node_t {
    void                *data;      /* Replace 'void' with desired data type */
    struct sllq_node_t   *next;      /* The address of the next SLLQ node */
} sllq_node_t;

// Keeping track of SLLQ data:
typedef struct sllq_list_t {
    sllq_node_t          *head;      /* Node at the START of the SLLQ */
    sllq_node_t          *tail;      /* Node at the END of the SLLQ */
    unsigned int        length;     /* Number of SLLQ nodes */
} sllq_list_t;

/* -------------------------------------------------------------------------- */

// SLLQ Operations:
sllq_list_t *sllq_init(void);
void sllq_free(sllq_list_t *sllq);
int sllq_is_empty(sllq_list_t *sllq);

sllq_node_t *sllq_enqueue(sllq_list_t *sllq, void *new_data);
sllq_node_t *sllq_dequeue(sllq_list_t *sllq);

sllq_node_t *sllq_get_head(sllq_list_t *sllq);
sllq_node_t *sllq_get_tail(sllq_list_t *sllq);
sllq_node_t *sllq_node_search(sllq_list_t *sllq, int (*cmp_fn)(void*, void*), void *target_data);

/* -------------------------------------------------------------------------- */