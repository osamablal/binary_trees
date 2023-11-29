#include "binary_trees.h"
/**
 * new_node - creating new node in linked list.
 * @node: Node we create.
 * Return: Node.
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new;

	new =  malloc(sizeof(link_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->nod = node;
	new->nxt = NULL;

	return (new);
}
/**
 * free_q - Freeing nodes at linked list.
 * @head: Node.
 */
void free_q(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->nxt;
		free(head);
		head = temp_node;
	}
}
/**
 * _push - Pushing node to stack.
 * @node: The Node.
 * @head: The Head.
 * @tail: The tail.
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->nxt = new;
	*tail = new;
}
/**
 * _pop - Poping node to stack.
 * @head: The Head.
 */
void _pop(link_t **head)
{
	link_t *temp_node;

	temp_node = (*head)->nxt;
	free(*head);
	*head = temp_node;
}
/**
 * binary_tree_is_complete - Checking if binary tree its complete.
 * @tree: The tree.
 * Return: 1 if is complete 0 if it is no.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->nod->lft != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->nod->lft, head, &tail);
		}
		else
			flag = 1;
		if (head->nod->rgt != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->nod->rgt, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
