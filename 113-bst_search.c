#include "binary_trees.h"

/**
 * bst_search - fxn that searches for a value in a BST
 * @tree: is a pointer to the root node of BST to search
 * @value: is the value to search in the tree
 * Return: A pointer to the node containing a value equal to `value`
 *         NULL if tree is NULL
 *         NULL if nothing is found
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
