#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as left-child of another node
 * @parent: pointer to the node to insert the left-child in it
 * @value: The value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tnew_node;

	if (parent == NULL)
		return (NULL);

	tnew_node = binary_tree_node(parent, value);
	if (tnew_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = tnew_node;
		tnew_node->left = parent->left;
	}
	parent->left = tnew_node;

	return (tnew_node);
}
