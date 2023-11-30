#include "binary_trees.h"
/**
 * binary_tree_preorder - printing parts of tree by preorder traversal.
 * @tree: tree we going in.
 * @func: The function.
 * Return: Nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
