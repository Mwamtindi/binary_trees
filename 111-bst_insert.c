#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: a double pointer to the root node of BST to insert the value
 * @value: the value to store in node to be inserted
 * Return: A pointer to created node
 *         NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *sec = NULL;
	bst_t *neww = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		sec = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	neww = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = neww;
	else if (value < sec->n)
	{
		sec->left = neww;
		neww->parent = sec;
	}
	else
	{
		sec->right = neww;
		neww->parent = sec;
	}

	return (neww);
}
