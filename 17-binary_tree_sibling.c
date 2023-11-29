#include "binary_trees.h"

/**
 * binary_tree_sibling - Finding if node is slbling.
 * @node: The Node.
 * Return: Sibling.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->lft == node)
		return (node->parent->rgt);
	return (node->parent->lft);
}
