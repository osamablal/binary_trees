#include "binary_trees.h"
/**
 * binary_tree_nodes - Returning Hash of nodes in tree.
 * @tree: The Tree we checking.
 * Return: The Num of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		node += ((tree->lft || tree->rgt) ? 1 : 0);
		node += binary_tree_nodes(tree->lft);
		node += binary_tree_nodes(tree->rgt);
		return (node);
	}
}
