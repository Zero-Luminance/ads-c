/**
 * @file    linked-list-queue.h
 * @brief   A header file for linked list queue (LLQ) implementation
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
 * @note    Before using this file REMEMBER to replace ALL instances of
 *          'void' associated with llq_node_t's 'data' component with
 *          desired data type.
*/
/* -------------------------------------------------------------------------- */

#define EMPTY_LIST 0
#define CMP_FN_EQUAL 0

/* -------------------------------------------------------------------------- */

// Connecting these creates a LLQ:
typedef struct llq_node_t {
    void                *data;      /* Replace 'void' with desired data type */
    struct llq_node_t   *next;      /* The address of the next LLQ node */
} llq_node_t;

// Keeping track of LLQ data:
typedef struct llq_list_t {
    llq_node_t          *head;      /* Node at the START of the LLQ */
    llq_node_t          *tail;      /* Node at the END of the LLQ */
    unsigned int        length;     /* Number of LLQ nodes */
} llq_list_t;

/* -------------------------------------------------------------------------- */

// LLQ Operations:
llq_list_t *llq_init(void);
void llq_free(llq_list_t *llq);
int llq_is_empty(llq_list_t *llq);

llq_node_t *llq_enqueue(llq_list_t *llq, void *new_data);
llq_node_t *llq_dequeue(llq_list_t *llq);

llq_node_t *llq_get_head(llq_list_t *llq);
llq_node_t *llq_get_tail(llq_list_t *llq);
llq_node_t *llq_node_search(llq_list_t *llq, int (*cmp_fn)(void*, void*), void *target_data);

/* -------------------------------------------------------------------------- */