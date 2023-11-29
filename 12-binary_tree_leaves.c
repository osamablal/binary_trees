#include "binary_trees.h"
/**
 * binary_tree_leaves - Returning num of parts in tree.
 * @tree: The tree we checking.
 * Return: num of parts.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, l = 0, r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = binary_tree_leaves(tree->lft);
		r = binary_tree_leaves(tree->rgt);
		leaf = l + r;
		return ((!l && !r) ? leaf + 1 : leaf + 0);
	}
}