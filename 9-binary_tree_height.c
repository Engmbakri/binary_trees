#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node
 * Return: 0 if tree is NULL, else return height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t A = 0, B = 0;

		A = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		B = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((A > B) ? A : B);
	}
	return (0);
}
