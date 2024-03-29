#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: Pointer to the root node
 *
 * Return: 0 if tree is NULL, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Pointer to the root node
 *
 * Return:  0 if tree is NULL, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t A = 0, B = 0;

		A = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		B = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((A > B) ? A : B);
	}
	return (0);
}
