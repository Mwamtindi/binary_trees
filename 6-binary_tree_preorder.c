#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes thro' a binary tree using pre-order traversal
 *
 * @tree: Pointer to  root node of the tree to traverse
 * @func: Pointer to a func to call for each node
 *
 * If tree or func is NULL do nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
