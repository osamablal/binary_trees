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
	size_t leaves;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	binary_tree_insert_right(root->lft, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	leaves = binary_tree_leaves(root);
	printf("Leaves in %d: %lu\n", root->n, leaves);
	leaves = binary_tree_leaves(root->rgt);
	printf("Leaves in %d: %lu\n", root->rgt->n, leaves);
	leaves = binary_tree_leaves(root->lft->rgt);
	printf("Leaves in %d: %lu\n", root->lft->rgt->n, leaves);
	return (0);
}
