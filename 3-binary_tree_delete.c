#include "binary_trees.h"

/**
 * binary_tree_delete - function delets binary tree
 * @tree: ponter to the root node
 * Return: Void
 * Discription: deletes an entire binary tree
*/

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
