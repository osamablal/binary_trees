#include "binary_trees.h"

/**
 * binary_tree_is_root -  Checking if node is root.
 * @node: The node we checking.
 * Return: 0 if is not root 1 if it is root.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
