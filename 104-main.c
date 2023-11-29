#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
  binary_tree_t *root;

  root = binary_tree_node(NULL, 98);
  root->lft = binary_tree_node(root, 64);
  root->lft->lft = binary_tree_node(root->lft, 32);
  binary_tree_print(root);
  printf("Rotate-right %d\n", root->n);
  root = binary_tree_rotate_right(root);
  binary_tree_print(root);
  printf("\n");

  root->lft->lft = binary_tree_node(root->lft, 20);
  root->lft->rgt = binary_tree_node(root->lft, 56);
  binary_tree_print(root);
  printf("Rotate-right %d\n", root->n);
  root = binary_tree_rotate_right(root);
  binary_tree_print(root);
  return (0);
}
