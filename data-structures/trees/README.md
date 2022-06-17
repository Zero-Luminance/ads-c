# TREES

## Directory Contents:
1) [Tree Implementations](#tree-implementations)
2) [Introduction To Trees](#introduction-to-trees)
3) [Types Of Trees](#types-of-trees)
4) [Binary Trees](#binary-trees)
5) [Unbounded Branching Trees](#unbounded-branching-trees)

## Tree Implementations:
- [Binary Search Trees (Unbalanced)]()
- [AVL Trees (Self-Balancing)]()
- [Red-Black Trees (Self-Balancing)]()
- [Trie: Radix]()
- [B Trees]()
- [Binary Heaps]()
- [Van Emde Boas Trees]()

## Introduction To Trees:
- ‘Trees’ is a hierarchical ABSTRACT data structure that consists of:
    - ‘Root’ node which is the TOP-MOST node in the tree
    - ‘Child’ nodes extend from a parent node located ABOVE it
    - ‘Parent’ nodes extends to other child node(s) BELOW it
    - ‘Sibling’ nodes involves child nodes with the SAME parent node
    - ‘Leaf’ is a node WITHOUT children
    - ‘Internal’ nodes have AT LEAST 1 child
- ‘Degree’ of a tree is the NUMBER of child nodes
- ‘Edge’ is the CONNECTION between nodes
- ‘Level’ is the NUMBER of parent nodes needed to reach the root node
- ‘Height’ is the length of the LONGEST downward path between the node & leaf


## Types Of Trees:
- ‘Rooted Tree’ are trees with a singled out node called the ROOT node
- ‘Free Trees’ are trees without a root node

## Binary Trees:
-‘Binary Trees’ permit a MAXIMUM of 2 child nodes per parent node
- Each binary tree node has:
    - TWO pointers (e.g. named ‘left’ & ‘right’) to potential CHILD nodes
    - ONE pointer to the PARENT node (e.g. named ‘p’ or ‘parent’)
    - ‘Key’ containing INFORMATION of an appropriate data type or structure

## Unbounded Branching Trees:
- ‘Unbounded Branching Trees’ are trees that employ an ’n’ number of child nodes per parent node
- A ‘Left-Child & Right-Child’ representation uses O(n) space that requires the PARENT node to ONLY store a pointer for the LEFT-MOST child node