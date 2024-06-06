#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on binary tree
 * @tree: Pointer to the root node of tree to rotate
 *
 * Return: Pointer to the new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *nw_root, *tem;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	nw_root = tree->left;
	tem = nw_root->right;

	nw_root->right = tree;
	tree->left = tem;

	if (tem != NULL)
		tem->parent = tree;

	nw_root->parent = tree->parent;
	tree->parent = new_root;

	return (nw_root);
}
