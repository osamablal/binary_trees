#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point testing comment
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);

	root->lft = binary_tree_node(root, 12);
	root->lft->lft = binary_tree_node(root->lft, 6);
	root->lft->rgt = binary_tree_node(root->lft, 16);

	root->rgt = binary_tree_node(root, 402);
	root->rgt->lft = binary_tree_node(root->rgt, 256);
	root->rgt->rgt = binary_tree_node(root->rgt, 512);

	binary_tree_print(root);
	return (0);
}

