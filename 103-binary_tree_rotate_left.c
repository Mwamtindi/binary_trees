#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on binary tree
 * @tree: Pointer to the root node of tree to rotate
 *
 * Return: Pointer to the new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *nw_root, *tem;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	nw_root = tree->right;
	tem = nw_root->left;

	nw_root->left = tree;
	tree->right = tem;

	if (tem != NULL)
		tem->parent = tree;

	nw_root->parent = tree->parent;
	tree->parent = nw_root;

	return (nw_root);
}
