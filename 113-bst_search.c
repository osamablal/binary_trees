#include "binary_trees.h"
/**
 * bst_search - Looking For specific value in tree.
 * @tree: The Tree.
 * @value: The Value.
 * Return: Node having the value or NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found = bst_search(tree->lft, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->rgt, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found);
}
