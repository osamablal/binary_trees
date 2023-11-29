#include "binary_trees.h"
/**
 * binary_tree_inorder - Printing parts of tree by inorder traversal.
 * @tree: The tree we go in.
 * @func: The function.
 * Return: Nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_inorder(tree->lft, func);
		func(tree->n);
		binary_tree_inorder(tree->rgt, func);
	}
}