#include "binary_trees.h"

/**
 * binary_tree_height_b - Measuring lenght of binary tree.
 * @tree: The Tree.
 * Return: Lenght.
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
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
			l = tree->lft ? 1 + binary_tree_height_b(tree->lft) : 1;
			r = tree->rgt ? 1 + binary_tree_height_b(tree->rgt) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - Measuring balanc factor of tree.
 * @tree: The Tree.
 * Return: balanc factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rgt = 0, lft = 0, total = 0;

	if (tree)
	{
		lft = ((int)binary_tree_height_b(tree->lft));
		rgt = ((int)binary_tree_height_b(tree->rgt));
		total = lft - rgt;
	}
	return (total);
}
