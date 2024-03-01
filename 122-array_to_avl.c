#include "binary_trees.h"

/**
 * array_to_avl - AVL tree from array.
 * @array: Pointer to element one
 * @size: Element number.
 * Return: Pointer node of created AVL else 0
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *wod = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&wod, array[i]) == NULL)
				return (NULL);
		}
	}

	return (wod);
}
