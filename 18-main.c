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
    binary_tree_t *uncle;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 128);
    root->lft->rgt = binary_tree_node(root->lft, 54);
    root->rgt->rgt = binary_tree_node(root->rgt, 402);
    root->lft->lft = binary_tree_node(root->lft, 10);
    root->rgt->lft = binary_tree_node(root->rgt, 110);
    root->rgt->rgt->lft = binary_tree_node(root->rgt->rgt, 200);
    root->rgt->rgt->rgt = binary_tree_node(root->rgt->rgt, 512);

    binary_tree_print(root);
    uncle = binary_tree_uncle(root->rgt->lft);
    printf("Uncle of %d: %d\n", root->rgt->lft->n, uncle->n);
    uncle = binary_tree_uncle(root->lft->rgt);
    printf("Uncle of %d: %d\n", root->lft->rgt->n, uncle->n);
    uncle = binary_tree_uncle(root->lft);
    printf("Uncle of %d: %p\n", root->lft->n, (void *)uncle);
    return (0);
}
