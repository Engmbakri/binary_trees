#include "binary_trees.h"

/**
 * binary_tree_insert_right - Function that insert a node as
 * the right-child of the parent node
 * @parent: pointer to the node in which the new node inserted
 * @value: value sorted in the new node
 * Return: NULL if an error occurs, else return the new node
 * Discription: If parent already has a right-child, the new node must take
 * its place and the old right-child must be set as
 * the right-child of the new node
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
