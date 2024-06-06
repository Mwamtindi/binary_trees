#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: pointer to the first element of array to be converted
 * @size: the number of elements in array
 * Return: A pointer to the root node of created BST
 *         NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int e;
	bst_t *root = NULL;

	for (e = 0; e < size; e++)
		bst_insert(&root, array[e]);

	return (root);
}
