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
	int left_ht, right_ht;

	if (tree == NULL)
		return (0);

	left_ht = binary_tree_height(tree->left);
	right_ht = binary_tree_height(tree->right);

	return (left_ht - right_ht);
}
