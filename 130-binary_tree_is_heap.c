#include "binary_trees.h"

/**
 * check_max - Binary check ropot is top value
 * @tree: Pointer root
 * Return: if all nodes are top return 1 else 0
 **/

int check_max(const binary_tree_t *tree)
{
	int p1 = 1;
	int p2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		p1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		p2 = check_max(tree->right);
	}
	return (p1 && p2);
}

/**
 * binary_tree_is_heap - check for tree binary heap
 * @tree: Pointer
 * Return: BTS then 1 else 0
 **/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int c;

	if (!tree)
		return (0);

	c = binary_tree_is_complete(tree);
	if (!c)
		return (0);
	return (check_max(tree));
}
