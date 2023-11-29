#include "binary_trees.h"
/**
 * successor - Having following successor.
 * @node: Checking.
 * Return: Minimum value of it.
 */
int successor(bst_t *node)
{
	int lft = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		lft = successor(node->lft);
		if (lft == 0)
		{
			return (node->n);
		}
		return (lft);
	}

}
/**
 * two_children - Having next successor using minimum.
 * @root: The node with two childs.
 * Return: we find.
 */
int two_children(bst_t *root)
{
	int new_value = 0;

	new_value = successor(root->rgt);
	root->n = new_value;
	return (new_value);
}
/**
 *remove_type - Removing node.
 *@root: The node.
 *Return: 0 if it have no childs.
 */
int remove_type(bst_t *root)
{
	if (!root->lft && !root->rgt)
	{
		if (root->parent->rgt == root)
			root->parent->rgt = NULL;
		else
			root->parent->lft = NULL;
		free(root);
		return (0);
	}
	else if ((!root->lft && root->rgt) || (!root->rgt && root->lft))
	{
		if (!root->lft)
		{
			if (root->parent->rgt == root)
				root->parent->rgt = root->rgt;
			else
				root->parent->lft = root->rgt;
			root->rgt->parent = root->parent;
		}
		if (!root->rgt)
		{
			if (root->parent->rgt == root)
				root->parent->rgt = root->lft;
			else
				root->parent->lft = root->lft;
			root->lft->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - Removeing node from bst tree.
 * @root: The Root.
 * @value: The Node.
 * Return: Tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->lft, value);
	else if (value > root->n)
		bst_remove(root->rgt, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->rgt, type);
	}
	else
		return (NULL);
	return (root);
}
