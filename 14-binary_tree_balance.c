#include "binary_trees.h"

/**
 * binary_tree_hght_b - fxn Measures height of a binary tree for a bal tree
 * @tree: pointer to the tree to go through
 * Return:  height
 */

size_t binary_tree_hght_b(const binary_tree_t *tree)
{
	size_t le = 0;
	size_t ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			le = tree->left ? 1 + binary_tree_hght_b(tree->left) : 1;
			ri = tree->right ? 1 + binary_tree_hght_b(tree->right) : 1;
		}
		return ((le > ri) ? le : ri);
	}
}

/**
 * binary_tree_balance - fxn Measures balance factor of binary tree
 * @tree: pointer to the tree to go through
 * Return: the balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, leftt = 0, tot = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		tot = left - right;
	}
	return (tot);
}
