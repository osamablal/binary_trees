#include "binary_trees.h"
/**
 * binary_tree_is_full - Finding if tree is full or no.
 * @tree: The Tree.
 * Return: 1 if it is full 0 if no.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lft = 0, rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->lft && tree->rgt)
		{
			lft = binary_tree_is_full(tree->lft);
			rgt = binary_tree_is_full(tree->rgt);
			if (lft == 0 || rgt == 0)
			{
				return (0);
			}
			return (1);
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
}
