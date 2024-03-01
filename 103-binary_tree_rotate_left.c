#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates left to binary
 * @tree: Pointer root node of the tree to rotate
 * Return: Pointer new
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *vi, *t;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	vi = tree->right;
	t = vi->left;
	vi->left = tree;
	tree->right = t;
	if (t != NULL)
		t->parent = tree;
	t = tree->parent;
	tree->parent = vi;
	vi->parent = t;
	if (t != NULL)
	{
		if (t->left == tree)
			t->left = vi;
		else
			t->right = vi;
	}
	return (vi);
}
