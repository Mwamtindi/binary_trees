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
	size_t left_ht, right_ht;

	if (tree == NULL)
		return (0);

	left_ht = binary_tree_height(tree->left);
	right_ht = binary_tree_height(tree->right);

	return ((left_ht > right_ht ? left_ht : right_ht) + 1);
}
