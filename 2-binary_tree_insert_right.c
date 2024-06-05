#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as right-child of another node
 *
 * @parent: Pointer to the node to insert right-child in it
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tnew_node;

	if (parent == NULL)
		return (NULL);

	tnew_node = binary_tree_node(parent, value);
	if (tnew_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		parent->right->parent = tnew_node;
		tnew_node->right = parent->right;
	}
	parent->right = tnew_node;

	return (tnew_node);
}
