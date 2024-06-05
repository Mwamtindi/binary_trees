#include "binary_trees.h"

/**
 * binary_tree_height - fxn that measures the height of  binary tree
 *
 * @tree: Pointer to root node of the tree to measure the height
 *
 * Return: Height of the tree or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_ht = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_ht = binary_tree_height(tree->right) + 1;
	if (left_ht >= right_ht)
		return (left_ht);
	else
		return (right_ht);
}
