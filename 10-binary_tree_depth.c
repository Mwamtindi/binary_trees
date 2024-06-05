#include "binary_trees.h"

/**
 * binary_tree_depth - fxn that measures depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure depth
 *
 * Return: Depth of the node. If tree is NULL return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dpt = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		dpt++;
		tree = tree->parent;
	}

	return (dpt);
}
