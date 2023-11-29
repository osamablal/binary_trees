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
	int perfect;

	root = binary_tree_node(NULL, 98);
	root->lft = binary_tree_node(root, 12);
	root->rgt = binary_tree_node(root, 402);
	binary_tree_insert_right(root->lft, 54);
	binary_tree_insert_right(root, 128);
	root->lft->lft = binary_tree_node(root->lft, 10);
	root->rgt->lft = binary_tree_node(root->rgt, 10);

	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->rgt->rgt->lft = binary_tree_node(root->rgt->rgt, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->rgt->rgt->rgt = binary_tree_node(root->rgt->rgt, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n", perfect);
	return (0);
}
