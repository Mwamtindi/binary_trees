#include "binary_trees.h"

/**
 * binary_tree_node - Creates  binary tree node
 *
 * @parent: Pointer to  parent node
 * @value: The value to put in the new node
 *
 * Return: Pointer to  new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tnew_node;

	tnew_node = malloc(sizeof(binary_tree_t));
	if (tnew_node == NULL)
		return (NULL);

	tnew_node->n = value;
	tnew_node->parent = parent;
	tnew_node->left = NULL;
	tnew_node->right = NULL;

	return (tnew_node);
}
