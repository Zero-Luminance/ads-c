/**
 * @file    red-black-tree.h
 * @brief   A header file for implementing a red-black tree (RBT)
 * @author  Jude Thaddeau Data (a.k.a Zero Luminance)
 * Github:  https://github.com/Zero-Luminance
*/
/* -------------------------------------------------------------------------- */

/**
 * @brief   A NODE when linked with others of the same kind creates a RBT
 * @param   color   0 indicates BLACK & 1 indicates RED
 * @param   key     The DATA stored within each RBT node
 * @param   parent  Pointer to the descendant node
 * @param   left    Pointer to the LEFT child (i.e. LESS)
 * @param   right   Pointer to the RIGHT child (i.e. GREATER)
*/
typedef struct rbt_node_t {
    int                 color;
    void                *key;
    struct rbt_node_t   *parent;
    struct rbt_node_t   *left;
    struct rbt_node_t   *right;
} rbt_node_t;

/**
 * @brief   A mechanism to interface with the RBT
 * @param   root    Pointer to the ROOT or 1st node in the RBT
 * @param   cmp_fn  Helps compare the keys within RBT nodes
*/
typedef struct rbt_tree_t {
    rbt_node_t          *root;
    int                 (*cmp_fn)(void*, void*);
} rbt_tree_t;

/* -------------------------------------------------------------------------- */

// BST OPERATIONS:


/* -------------------------------------------------------------------------- */