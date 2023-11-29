#include "binary_trees.h"
/**
 * bst_insert - Inserting nodes to create bst tree.
 * @tree: The tree.
 * @value: The value.
 * Return: Tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->lft)
				new = bst_insert(&temp->lft, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->lft = (bst_t *)aux;
			}
		}
		else if (value > temp->n)
		{
			if (temp->rgt)
				new = bst_insert(&temp->rgt, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->rgt = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
