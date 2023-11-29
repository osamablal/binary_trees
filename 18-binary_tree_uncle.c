#include "binary_trees.h"

/**
 * binary_tree_uncle - Finding if node is sibling.
 * @node: The Node.
 * Return: Node.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->parent->lft == node->parent)
		return (node->parent->parent->rgt);
	return (node->parent->parent->lft);
}
