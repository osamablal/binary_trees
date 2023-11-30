#include "binary_trees.h"

/**
 * binary_tree_node - Creating binary tree nod.
 * @parent: The perent node.
 * @value: The Value.
 *
 * Return: a pointer to new node, or NUL if fail.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
