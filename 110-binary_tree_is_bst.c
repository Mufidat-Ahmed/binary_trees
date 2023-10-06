#include "binary_trees.h"

/**
 * is_bst - checks if the binary tree satisfies the BST properties
 * @tree: pointer to the root node of the tree to check
 * @min: minimum allowed value for the current node
 * @max: maximum allowed value for the current node
 * Return: 1 if tree is a valid bst
 */

int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);
	if ((min != NULL && tree->n <= min->n) || (max != NULL &&
				tree->n >= max->n))
		return (0);
	return (is_bst(tree->left, min, tree) && is_bst(tree->right, tree, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return is_bst(tree, NULL, NULL);
}
