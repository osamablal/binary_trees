#include "binary_trees.h"
/**
 * binary_tree_insert_left - Adding node in left of parent .
 * @parent: The Parent of specific node.
 * @value: Node Value.
 * Return: NULL in failing.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->lft != NULL)
	{
		new_node->lft = parent->lft;
		parent->lft->parent = new_node;
	}
	parent->lft = new_node;
	return (new_node);
}