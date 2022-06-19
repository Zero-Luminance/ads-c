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

/* -------------------------------------------------------------------------- */