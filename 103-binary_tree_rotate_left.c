#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotating the left binary tree.
 * @tree: The tree.
 * Return: New node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->rgt == NULL)
	{
		return (NULL);
	}
	pivot = tree->rgt;
	tree->rgt = pivot->lft;
	if (pivot->lft != NULL)
	{
		pivot->lft->parent = tree;
	}
	pivot->lft = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
