#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_so - The binary tree node.
 *
 * @n: The interer store at node.
 * @parent: Parent node.
 * @left: The Left child node.
 * @right: The Right child node.
 */
struct binary_tree_so
{
	int n;
	struct binary_tree_so *parent;
	struct binary_tree_so *left;
	struct binary_tree_so *right;
};
typedef struct binary_tree_so binary_tree_t;
typedef struct binary_tree_so bst_t;
typedef struct binary_tree_so avl_t;
typedef struct binary_tree_so heap_t;

/**
 * struct link_so - The Structure of The advance tasks.
 *
 * @n: The Depth of the node.
 * @node: The node of the tree.
 * @next: The next node of list.
 */
typedef struct link_so
{
	size_t n;
	struct binary_tree_so const *node;
	struct link_so *next;
} link_t;
/*  ----------------- mandatory task ---------------------------------*/
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);

#endif /* Binary-Trees-h */
