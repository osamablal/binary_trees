#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
    binary_tree_t *ancestor;

    ancestor = binary_trees_ancestor(n1, n2);
    printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
    if (!ancestor)
        printf("(nil)\n");
    else
        printf("%d\n", ancestor->n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->lft = binary_tree_node(root, 12);
    root->rgt = binary_tree_node(root, 402);
    root->lft->rgt = binary_tree_node(root->lft, 54);
    root->rgt->rgt = binary_tree_node(root->rgt, 128);
    root->lft->lft = binary_tree_node(root->lft, 10);
    root->rgt->lft = binary_tree_node(root->rgt, 45);
    root->rgt->rgt->lft = binary_tree_node(root->rgt->rgt, 92);
    root->rgt->rgt->rgt = binary_tree_node(root->rgt->rgt, 65);
    binary_tree_print(root);

    launch_test(root->lft, root->rgt);
    launch_test(root->rgt->lft, root->rgt->rgt->rgt);
    launch_test(root->rgt->rgt, root->rgt->rgt->rgt);
    return (0);
}
