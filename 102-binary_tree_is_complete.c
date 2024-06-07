#include "binary_trees.h"

/**
 * binary_tree_is_complete - fxn that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t numb;

	if (!tree)
		return (0);
	numb = binary_tree_size(tree);

	return (assist_bt_isco(tree, 0, numb));
}

/**
 * assist_bt_isco - fxn that checks if a binary tree is complete
 * @tree: a pointer to root node of the tree to check
 * @btid: pointer to the node to be checked
 * @numb: the number of nodes in the binary tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete, 0 if tree is NULL
 */
int assist_bt_isco(const binary_tree_t *tree, size_t btid, size_t numb)
{
	if (!tree)
		return (1);

	if (btid >= numb)
		return (0);

	return (assist_bt_isco(tree->left, 2 * btid + 1, numb) &&
		assist_bt_isco(tree->right, 2 * btid + 2, numb));
}

/**
 * binary_tree_size - fxn that measures the size of binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
