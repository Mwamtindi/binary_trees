#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in binary tree
 * @tree: Pointer to the node to measure depth
 *
 * Return: Depth of the node or 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dpt = 0;

	while (tree && tree->parent)
	{
		dpt++;
		tree = tree->parent;
	}

	return (dpt);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t dpt_first, dpt_second;

	if (first == NULL || second == NULL)
		return (NULL);

	dpt_first = binary_tree_depth(first);
	dpt_second = binary_tree_depth(second);

	/* move up the tree from the deeper node */
	while (dpt_first > dpt_second)
	{
		first = first->parent;
		dpt_first--;
	}
	while (dpt_second > dpt_first)
	{
		second = second->parent;
		dpt_second--;
	}

	/* move both nodes up together until a common ancestor is found */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
