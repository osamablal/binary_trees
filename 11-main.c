#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t size;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	binary_tree_insert_right(root->lft, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	size = binary_tree_size(root);
	printf("Size of %d: %lu\n", root->n, size);
	size = binary_tree_size(root->rgt);
	printf("Size of %d: %lu\n", root->rgt->n, size);
	size = binary_tree_size(root->lft->rgt);
	printf("Size of %d: %lu\n", root->lft->rgt->n, size);
	return (0);
}
