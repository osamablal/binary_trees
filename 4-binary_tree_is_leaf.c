#include "binary_trees.h"
/**
 * binary_tree_is_leaf - finding if the node is leaf or no.
 * @node: The node we study.
 * Return: 1 if it is a leaf or 0 if no.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
