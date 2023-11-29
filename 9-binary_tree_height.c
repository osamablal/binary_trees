#include "binary_trees.h"

/**
 * binary_tree_height - Measuring lenght of the binary tree.
 * @tree: The Tree.
 * Return: Lenght.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->lft ? 1 + binary_tree_height(tree->lft) : 0;
			r = tree->rgt ? 1 + binary_tree_height(tree->rgt) : 0;
		}
		return ((l > r) ? l : r);
	}
}
