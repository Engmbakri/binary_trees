#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: Pointer to the root node
 *
 * Return: Number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_number = 0;

	if (tree)
	{
		leaves_number += (!tree->left && !tree->right) ? 1 : 0;
		leaves_number += binary_tree_leaves(tree->left);
		leaves_number += binary_tree_leaves(tree->right);
	}
	return (leaves_number);
}
