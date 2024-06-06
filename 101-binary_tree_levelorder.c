#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: Height of the tree or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt_height, rt_height;

	if (tree == NULL)
		return (0);

	lt_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rt_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lt_height > rt_height ? lt_height : rt_height);
}

/**
 * print_curr_level - Helper function to print nodes at current level
 * @tree: Pointer to the root node of tree to traverse
 * @level: The current level to print
 * @func: Pointer to function to call for each node
 */

void print_curr_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_curr_level(tree->left, level - 1, func);
		print_curr_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes thro' binary tree using levelorder traversal
 * @tree: Pointer to the root node of tree to traverse
 * @func: Pointer to function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t ht;
	size_t e;

	if (tree == NULL || func == NULL)
		return;

	ht = binary_tree_height(tree);

	for (e = 1; e <= ht + 1; e++)
		print_current_level(tree, e, func);
}
