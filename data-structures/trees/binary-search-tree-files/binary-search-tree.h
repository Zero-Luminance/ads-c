/**
 * @file    binary-search-tree.h
 * @brief   A header file for implementing a binary search tree (BST)
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a BST
 * @param   key     The DATA stored within each BST node
 * @param   parent  Pointer to the descendant node
 * @param   left    Pointer to the LEFT child (i.e. LESS)
 * @param   right   Pointer to the RIGHT child (i.e. GREATER)
*/
typedef struct bst_node_t {
    void                *key;
    struct bst_node_t   *parent;
    struct bst_node_t   *left;
    struct bst_node_t   *right;
} bst_node_t;

/**
 * @brief   A mechanism to interface with the BST
 * @param   root    Pointer to the ROOT or 1st node in the BST
 * @param   cmp_fn  Helps compare the keys within BST nodes
*/
typedef struct bst_tree_t {
    bst_node_t          *root;
    int                 (*cmp_fn)(void*, void*);
} bst_tree_t;

/* -------------------------------------------------------------------------- */

// BST OPERATIONS:
bst_tree_t *bst_init(int cmp(void*, void*));
void bst_free(bst_tree_t *bst);
int bst_is_empty(bst_tree_t *bst);

void bst_inorder(bst_tree_t *bst, void action(void*));
void bst_preorder(bst_tree_t *bst, void action(void*));
void bst_postorder(bst_tree_t *bst, void action(void*));

bst_node_t *bst_search(bst_tree_t *bst, void *search_key);
static bst_node_t *bst_recursive_search(bst_node_t *root, void *search_key, int cmp(void*, void*));
static bst_node_t *bst_iterative_search(bst_node_t *root, void *search_key, int cmp(void*, void*));

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