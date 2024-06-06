#include "binary_trees.h"
/**
 * success - get the next min node in the right subtree
 * @node: pointer to the tree to check
 * Return: min value of this tree
 */

int success(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = success(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}
/**
 * lnr_children - func that gets the next successor using the min
 * value in the right subtree, and then replace the node value for
 * this successor
 * @root: node that has two children
 * Return: the actual value found
 */

int lnr_children(bst_t *root)
{
	int n_value = 0;

	n_value = success(root->right);
	root->n = n_value;
	return (n_value);
}
/**
 *type_remove - func that removes a node depending on its children
 *@root: pointer to the node to remove
 *Return: 0 if it has no children, or other value if it has children
 */

int type_remove(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (lnr_children(root));
}
/**
 * bst_remove - fxn that removes a node from a BST tree
 * @root: pointer to the root of the tree
 * @value: the value to remove in the tree
 * Return: changes tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = type_remove(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
