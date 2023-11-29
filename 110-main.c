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
  int bst;

  root = binary_tree_node(NULL, 98);
  root->lft = binary_tree_node(root, 12);
  root->rgt = binary_tree_node(root, 128);
  root->lft->rgt = binary_tree_node(root->lft, 54);
  root->rgt->rgt = binary_tree_node(root, 402);
  root->lft->lft = binary_tree_node(root->lft, 10);

  binary_tree_print(root);
  bst = binary_tree_is_bst(root);
  printf("Is %d bst: %d\n", root->n, bst);
  bst = binary_tree_is_bst(root->lft);
  printf("Is %d bst: %d\n", root->lft->n, bst);

  root->rgt->lft = binary_tree_node(root->rgt, 97);
  binary_tree_print(root);
  bst = binary_tree_is_bst(root);
  printf("Is %d bst: %d\n", root->n, bst);
  return (0);
}
