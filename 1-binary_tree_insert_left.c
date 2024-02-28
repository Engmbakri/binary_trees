#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function insert a node as
 * a lef-child of parent node
 * @parent: ponter to the node in which new node inserted
 * @value: value of the new node
 * Return: error if an error occurs, else return the new node
 * Description: if the parent already has a left-child
 * the new node takes it place
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
