#include "binary_trees.h"
/**
 * check_sub_tree_Left - Checking if nodes smaller root.
 * @node: The node.
 * @max: Comparing.
 * Return: 1 if all nodes are smaller or equal or 0 if no.
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int lft = 0, rgt = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lft = check_sub_tree_Left(node->lft, max);
		rgt = check_sub_tree_Left(node->rgt, max);
		if (lft == rgt && lft == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - Chcking if nodes are bigger root.
 * @node: The node.
 * @min: coparing.
 * Return: 1 if all is bigger or equal or 0 if no.
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_Right(node->lft, min);
		right = check_sub_tree_Right(node->rgt, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - Finding if tree is good or no.
 * @tree: The Tree.
 * Return: 1 if it is or 0 if no.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, lft = 2, rgt = 2;

	if (tree == NULL)
		return (0);
	if (tree->lft && tree->lft->n > tree->n)
		return (0);
	if (tree->rgt && tree->rgt->n < tree->n)
		return (0);
	if (tree->lft && tree->lft->n < tree->n)
	{
		var = check_sub_tree_Left(tree->lft, tree->n);
		if (var == 0)
			return (0);
		lft = binary_tree_is_bst(tree->lft);
	}
	if (tree->rgt && tree->rgt->n > tree->n)
	{
		var = check_sub_tree_Right(tree->rgt, tree->n);
		if (var == 0)
			return (0);
		rgt = binary_tree_is_bst(tree->rgt);
	}
	if (lft != 2 || rgt != 2)
	{
		if (lft == 0 || rgt == 0)
			return (0);
	}
	return (1);
}
