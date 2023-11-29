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
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 402);
    binary_tree_insert_right(root->lft, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->rgt);
    printf("Height from %d: %lu\n", root->rgt->n, height);
    height = binary_tree_height(root->lft->rgt);
    printf("Height from %d: %lu\n", root->lft->rgt->n, height);
    return (0);
}