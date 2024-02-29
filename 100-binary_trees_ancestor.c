#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node.
 *
 * Return: if not found return NULL. Pointer to the lowest common ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
        binary_tree_t *mam, *babo;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mam = first->parent, babo = second->parent;
	if (first == babo || !mam || (!mam->parent && babo))
		return (binary_trees_ancestor(first, babo));
	else if (mam == second || !babo || (!babo->parent && mam))
		return (binary_trees_ancestor(mam, second));
	return (binary_trees_ancestor(mam, babo));
}
