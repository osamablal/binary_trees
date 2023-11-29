#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 128);
    root->lft->rgt = binary_tree_node(root->lft, 54);
    root->rgt->rgt = binary_tree_node(root, 402);
    root->lft->lft = binary_tree_node(root->lft, 10);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int avl;

    root = basic_tree();

    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);
    avl = binary_tree_is_avl(root->lft);
    printf("Is %d avl: %d\n", root->lft->n, avl);

    root->rgt->lft = binary_tree_node(root->rgt, 97);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);

    root = basic_tree();
    root->rgt->rgt->rgt = binary_tree_node(root->rgt->rgt, 430);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);

    root->rgt->rgt->rgt->lft = binary_tree_node(root->rgt->rgt->rgt, 420);
    binary_tree_print(root);
    avl = binary_tree_is_avl(root);
    printf("Is %d avl: %d\n", root->n, avl);
    return (0);
}
