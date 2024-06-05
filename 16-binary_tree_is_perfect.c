#include "binary_trees.h"

/**
 * binary_tree_is_perfect - fxn that checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of tree to check
 *
 * Return: 1 if the tree is perfect 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t ht, sz, e;

	if (tree == NULL)
		return (0);

	ht = binary_tree_height(tree);
	sz = binary_tree_size(tree);

	for (e = 0; e <= ht; e++)
	{
		if (sz == (1 << e))
			return (1);
	}

	return (0);
}
