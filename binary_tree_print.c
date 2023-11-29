#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * print_t - Storing recursivly lavels in array of strings.
 *
 * @tree: The Tree.
 * @offset: The Offset.
 * @depth: The Depth.
 * @s: The Buffering.
 *
 * Return: lenght.
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, lft, rgt, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->lft == tree);
	width = sprintf(b, "(%03d)", tree->n);
	lft = print_t(tree->lft, offset, depth + 1, s);
	rgt = print_t(tree->rgt, offset + lft + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + lft + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + rgt; i++)
			s[depth - 1][offset + lft + width / 2 + i] = '-';
		s[depth - 1][offset + lft + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < lft + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + lft + width / 2] = '.';
	}
	return (lft + width + rgt);
}

/**
 * _height - Measuring lenght of binary tree.
 *
 * @tree: The tree.
 *
 * Return: Lenght.
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->lft ? 1 + _height(tree->lft) : 0;
	height_r = tree->rgt ? 1 + _height(tree->rgt) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Printing binary tree.
 *
 * @tree: The Tree.
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
