#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of binary tree
 *
 * @tree: Pointer to the root node of the tree to measure balance factor
 *
 * Return: Balance factor of the tree. If tree is NULL return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_ht = binary_tree_height(tree->left);
	int right_ht = binary_tree_height(tree->right);


	return (left_ht - right_ht);
}

/**
 * binary_tree_height - Measures the height of binary tree.
 * @tree: A pointer to the root node of the tree to measure height.
 * Return: The height of the binary tree. If tree is NULL return 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_ht = binary_tree_height(tree->left);
	size_t right_ht = binary_tree_height(tree->right);

	return (1 + ((left_ht > right_ht) ? left_ht : right_ht));
}
