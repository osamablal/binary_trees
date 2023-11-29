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
    int balance;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 402);
    binary_tree_insert_right(root->lft, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->lft, 50);
    binary_tree_insert_left(root->lft->lft, 10);
    binary_tree_insert_left(root->lft->lft->lft, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root->n, balance);
    balance = binary_tree_balance(root->rgt);
    printf("Balance of %d: %+d\n", root->rgt->n, balance);
    balance = binary_tree_balance(root->lft->lft->rgt);
    printf("Balance of %d: %+d\n", root->lft->lft->rgt->n, balance);
    return (0);
}
