#include "binary_trees.h"
/**
 * binary_tree_postorder - Printing parts of tree by postorder traversal.
 * @tree: The tree we go in.
 * @func: The Function.
 * Return: Nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->lft, func);
		binary_tree_postorder(tree->rgt, func);
	}
	func(tree->n);
}
