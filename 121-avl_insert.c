#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Scale the height of tree binary
 * @tree: Pointer scale height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Scale the balance fac of tree binary
 * @tree: Pointer is equal fac.
 * Return: 0 if tree equal to NULL, else return the fac
 */

int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Put Value to tree AVL
 * @tree: 2 Pointer to root node tree AVL
 * @parent: Parent node
 * @new: 2 Pointer to node.
 * @value: The value to put tree AVL
 * Return: Pointer new root ekse NULL
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int fac;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	fac = balance(*tree);
	if (fac > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (fac < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (fac > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (fac < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Put value to AVL
 * @tree: 2 pointer to node of tree AVL
 * @value: Value insert AVL
 * Return: Pointer to node, for failuare NULl
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *s = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &s, value);
	return (s);
}
