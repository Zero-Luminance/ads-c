/**
 * @file    binary-search-tree.h
 * @brief   A header file for implementing a binary search tree (BST)
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

// Conncting these nodes creates a BST
typedef struct bst_node_t {
    void                *key;       // The DATA to be stored in the BST node
    struct bst_node_t   *parent;    // Pointer to the DESCENDANT node
    struct bst_node_t   *left;      // Left CHILD pointer (i.e. LESS)
    struct bst_node_t   *right;     // Right CHILD pointer (i.e. GREATER)
} bst_node_t;

// A mechansim to interface the BST
typedef struct bst_tree_t {
    struct bst_node_t   *root;                      // The 1st node in the BST
    int                 (*cmp_fn)(void*, void*);    // Compares 'key' equality
} bst_tree_t;

/* -------------------------------------------------------------------------- */

// BST Operations:
bst_tree_t *bst_init(void);
void bst_free(bst_tree_t *bst);
int bst_is_empty(bst_tree_t *bst);

void bst_inorder(bst_tree_t *bst, void action(void*));
void bst_preorder(bst_tree_t *bst, void action(void*));
void bst_postorder(bst_tree_t *bst, void action(void*));

bst_node_t *bst_search(bst_tree_t *bst, void *search_key);
static bst_node_t *bst_recursive_search(bst_node_t *root, void *search_key, int cmp(void*, void*));
static bast_node_t *bst_iterative_search(bst_node_t *root, void *search_key, int cmp(void*, void*));

bst_node_t *bst_minimum(bst_tree_t *bst);
bst_node_t *bst_maximum(bst_tree_t *bst);

bst_node_t *bst_predecessor(bst_tree_t *bst);
bst_node_t *bst_successor(bst_tree_t *bst);

bst_node_t *bst_insert(bst_tree_t *bst, void *new_key);
static bst_node_t *bst_recursive_insert(bst_node_t *root, bst_node_t *new_node, int cmp(void*, void*));
static bst_node_t *bst_iterative_insert(bst_node_t *root, bst_node_t *new_node, int cmp(void*, void*));

void bst_transplant(bst_tree_t *bst, bst_node_t *target, bst_node_t *replacement);
static void bst_delete(bst_tree_t *bst, void *target_key);
static void bst_recursive_delete(bst_tree_t *bst, bst_node_t *target);

/* -------------------------------------------------------------------------- */