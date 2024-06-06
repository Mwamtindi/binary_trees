#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if binary tree is a valid BST
 * @tree: a pointer to the root node of tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise, 0 if tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_help(tree, INT_MIN, INT_MAX));
}

/**
 * btib_help - checks if a binary tree is a valid BST
 * @tree: a pointer to the root node of tree to check
 * @min: Lower bound of checked nodes
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */

int btib_help(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_help(tree->left, min, tree->n - 1) &&
		btib_help(tree->right, tree->n + 1, max));
}
