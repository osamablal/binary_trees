#include "binary_trees.h"

/**
 * binary_tree_node - Creating binary node.
 * @parent: The parent of node.
 * @value: The node value.
 * Return: New Node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->lft = NULL;
	new_node->rgt = NULL;
	return (new_node);
}