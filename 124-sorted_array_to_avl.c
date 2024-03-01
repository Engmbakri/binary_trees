#include "binary_trees.h"

/**
 * create_tree - make AVL with recursion
 * @node: Pointer for nod
 * @array: array of integers
 * @size: array size
 * @mode: 1 for left, 2 for right
 * Return: None
 */

void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t c;

	if (size == 0)
		return;

	c = (size / 2);
	c = (size % 2 == 0) ? c - 1 : c;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[c]);
		create_tree(&((*node)->left), array, c, 1);
		create_tree(&((*node)->left), array + c + 1, (size - 1 - c), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[c]);
		create_tree(&((*node)->right), array, c, 1);
		create_tree(&((*node)->right), array + c + 1, (size - 1 - c), 2);
	}
}

/**
 * sorted_array_to_avl - creates
 *
 * @array: Array of integer
 * @size: Array size
 * Return: Pointer root
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *j;
	size_t c;

	j = NULL;

	if (size == 0)
		return (NULL);

	c = (size / 2);
	c = (size % 2 == 0) ? c - 1 : c;

	root = binary_tree_node(root, array[c]);

	create_tree(&root, array, c, 1);
	create_tree(&root, array + c + 1, (size - 1 - c), 2);

	return (root);
}
