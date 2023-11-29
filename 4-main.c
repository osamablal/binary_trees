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
	int ret;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	binary_tree_insert_right(root->lft, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	ret = binary_tree_is_leaf(root);
	printf("Is %d a leaf: %d\n", root->n, ret);
	ret = binary_tree_is_leaf(root->rgt);
	printf("Is %d a leaf: %d\n", root->rgt->n, ret);
	ret = binary_tree_is_leaf(root->rgt->rgt);
	printf("Is %d a leaf: %d\n", root->rgt->rgt->n, ret);
	return (0);
}
