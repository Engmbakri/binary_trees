#include "binary_trees.h"

/**
 * binary_tree_sibling - Function that finds sibling of a
 *                       node in a binary tree.
 * @node: Pointer to the node to
 *
 * Return: NULL if node is NULL or there is no sibling.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
