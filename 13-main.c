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
    size_t nodes;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 402);
    binary_tree_insert_right(root->lft, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    nodes = binary_tree_nodes(root);
    printf("Nodes in %d: %lu\n", root->n, nodes);
    nodes = binary_tree_nodes(root->rgt);
    printf("Nodes in %d: %lu\n", root->rgt->n, nodes);
    nodes = binary_tree_nodes(root->lft->rgt);
    printf("Nodes in %d: %lu\n", root->lft->rgt->n, nodes);
    return (0);
}
