#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - fxn that checks if a binary tree is complete
 * @tree: Pointer to the root node of tree to check
 *
 * Return: 1 if the tree is complete otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	size_t front = 0, rear = 0;
	int flag = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(*queue) * (binary_tree_sz(tree) + 1));
	if (queue == NULL)
		return (0);

	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		if (current)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
		else
		{
			flag = 1;
		}
	}

	free(queue);
	return (1);
}

/**
 * binary_tree_sz - fxn that measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure size
 *
 * Return: Size of the tree or 0 if tree is NULL
 */

size_t binary_tree_sz(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_sz(tree->left) + binary_tree_sz(tree->right));
}
