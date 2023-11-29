#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
	printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	root->lft->lft = binary_tree_node(root->lft, 6);
	root->lft->rgt = binary_tree_node(root->lft, 56);
	root->rgt->lft = binary_tree_node(root->rgt, 256);
	root->rgt->rgt = binary_tree_node(root->rgt, 512);

	binary_tree_print(root);
	binary_tree_preorder(root, &print_num);
	return (0);
}
