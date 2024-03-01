#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates right a tree binary
 * @tree: A pointer to the root node of the tree to rotate
 * Return: Pointer new
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *vi, *t;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	vi = tree->left;
	t = vi->right;
	vi->right = tree;
	tree->left = t;
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
