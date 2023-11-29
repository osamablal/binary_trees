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
	size_t depth;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	binary_tree_insert_right(root->lft, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	depth = binary_tree_depth(root);
	printf("Depth of %d: %lu\n", root->n, depth);
	depth = binary_tree_depth(root->rgt);
	printf("Depth of %d: %lu\n", root->rgt->n, depth);
	depth = binary_tree_depth(root->lft->rgt);
	printf("Depth of %d: %lu\n", root->lft->rgt->n, depth);
	return (0);
}
