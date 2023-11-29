#include "binary_trees.h"
/**
 * binary_tree_height - Measureing lenght of binary tree.
 * @tree: The Tree.
 * Return: Lenght.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->lft ? 1 + binary_tree_height(tree->lft) : 0;
			r = tree->rgt ? 1 + binary_tree_height(tree->rgt) : 0;
		}
		return ((l > r) ? l : r);
	}
}
/**
 * binary_tree_depth - The Depth of specific node.
 * @tree: Checking.
 * Return: 0 is it is the root or numb of d.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * linked_node - Making linked list from depth and node.
 * @head: Head of linked list.
 * @tree: Storing.
 * @level: The Depth.
 * Return: Nothing.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->nod = tree;
	if (*head == NULL)
	{
		new->nxt = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->nxt != NULL)
		{
			aux = aux->nxt;
		}
		new->nxt = NULL;
		aux->nxt = new;
	}
}
/**
 * recursion - Going in tree and each one stores node.
 * @head: The Head.
 * @tree: Checking.
 * Return: Nothing.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->lft);
		recursion(head, tree->rgt);
	}
}
/**
 * binary_tree_levelorder - Printing nodes in leverorder.
 * @tree: The Root.
 * @func: The Function.
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->nod->n);
				}
				aux = aux->nxt;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->nxt;
			free(aux);
		}
	}
}
