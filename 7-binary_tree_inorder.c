#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes thro' a binary tree using in-order traversal
 *
 * @tree: Pointer to  root node of the tree to traverse
 * @func: Pointer to a func to call for each node
 *
 * If tree or func is NULL do nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
