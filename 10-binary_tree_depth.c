#include "binary_trees.h"
/**
 * binary_tree_depth - The Depth of specific node of root.
 * @tree: The node for checking depth.
 * Return: 0 is its root or num of depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth += 1;
		tree = tree->parent;
	}

	return (depth);
}
