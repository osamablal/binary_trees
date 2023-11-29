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
    int complete;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 128);
    root->lft->rgt = binary_tree_node(root->lft, 54);
    root->rgt->rgt = binary_tree_node(root, 402);
    root->lft->lft = binary_tree_node(root->lft, 10);
    root->rgt->lft = binary_tree_node(root->rgt, 45);

    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);
    complete = binary_tree_is_complete(root->lft);
    printf("Is %d complete: %d\n", root->lft->n, complete);

    root->rgt->lft = binary_tree_node(root->rgt, 112);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    root->lft->lft->lft = binary_tree_node(root->lft->lft, 8);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    root->lft->rgt->lft = binary_tree_node(root->lft->rgt, 23);
    binary_tree_print(root);
    complete = binary_tree_is_complete(root);
    printf("Is %d complete: %d\n", root->n, complete);

    binary_tree_delete(root);
    return (0);
}
