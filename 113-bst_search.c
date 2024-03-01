#include "binary_trees.h"

/**
 * bst_search - Searche value in a tree search binary .
 * @tree: Pointer root node BST Search.
 * @value: Value search in BST
 * Return: If tree 0 or the value 0 do nothing
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
