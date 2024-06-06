#include "binary_trees.h"

/**
 * binary_tree_height_btr - Measures height of binary tree for a bal tree
 * @tree: pointer to the node to go through
 * Return: height given
 */

size_t binary_tree_height_btr(const binary_tree_t *tree)
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
			le = tree->left ? 1 + binary_tree_height_btr(tree->left) : 1;
			ri = tree->right ? 1 + binary_tree_height_btr(tree->right) : 1;
		}
		return ((le > ri) ? le : ri);
	}
}

/**
 * binary_tree_balance - Measures balance factor of binary tree
 * @tree: pointer to the root node of tree to measure the balance factor
 * Return: if tree is NULL return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rt = 0, lt = 0, ttl = 0;

	if (tree)
	{
		lt = ((int)binary_tree_height_b(tree->left));
		rt = ((int)binary_tree_height_b(tree->right));
		ttl = lt - rt;
	}
	return (ttl);
}
