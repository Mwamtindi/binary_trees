#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes thro' binary tree using level-order traversal
 * @tree: pointer to the root node of tree to traverse
 * @func: pointer to a func to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t bt_level, levelo;

	if (!tree || !func)
		return;

	levelo = binary_tree_height(tree) + 1;

	for (bt_level = 1; bt_level <= levelo; bt_level++)
		assist_bt_lo(tree, func, bt_level);
}

/**
 * assist_bt_lo - fxt to go thro' binary tree using post-order traverse
 * @tree: pointer to tree to traverse
 * @func: pointer to a func to call for each node
 * @level: level of the tree to call func upon
 */
void assist_bt_lo(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		assist_bt_lo(tree->left, func, level - 1);
		assist_bt_lo(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - fxn that measures the height of binary tree
 * @tree: pointer to measure the height of a node
 *
 * Return: height of tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_le = 0;
	size_t height_ri = 0;

	if (!tree)
		return (0);

	height_le = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_ri = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_le > height_ri ? height_le : height_ri);
}
