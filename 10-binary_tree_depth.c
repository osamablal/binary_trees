#include "binary_trees.h"
/**
 * binary_tree_depth - The Depth of specific node of root.
 * @tree: The node for checking depth.
 * Return: 0 is its root or num of depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
