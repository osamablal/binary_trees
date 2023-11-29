#include "binary_trees.h"
/**
 * binary_tree_delete - Freeing all the tree by recurse.
 * @tree: The tree we free.
 * Return: Nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->lft);
			binary_tree_delete(tree->rgt);
		}
		free(tree);
	}

}
