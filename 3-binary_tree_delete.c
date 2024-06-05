#include "binary_trees.h"

/**
 * binary_tree_delete - fxn that deletes an entire binary tree
 *
 * @tree: Pointer to root node of the tree to delete
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Recursively delete the left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Deletes current node */
	free(tree);
}
