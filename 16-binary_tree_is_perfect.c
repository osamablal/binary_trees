#include "binary_trees.h"
/**
 * tree_is_perfect - Finding if tree is perfect or no.
 * @tree: The Tree.
 * Return: 0 if is not perfect.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->lft && tree->rgt)
	{
		l = 1 + tree_is_perfect(tree->lft);
		r = 1 + tree_is_perfect(tree->rgt);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->lft && !tree->rgt)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - The tree is perfect or no.
 * @tree: The Tree.
 * Return: 1 is it is or 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}