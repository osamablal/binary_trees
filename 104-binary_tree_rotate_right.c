#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotating The Right binary tree.
 * @tree: The tree.
 * Return: New node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->lft == NULL)
	{
		return (NULL);
	}
	pivot = tree->lft;
	tree->lft = pivot->rgt;
	if (pivot->rgt != NULL)
	{
		pivot->rgt->parent = tree;
	}
	pivot->rgt = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
