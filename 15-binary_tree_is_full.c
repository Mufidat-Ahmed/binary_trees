#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int full_left, full_right;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	full_left = binary_tree_is_full(tree->left);
	full_right = binary_tree_is_full(tree->right);
	if (full_left && full_right)
	{
		return (1);
	}
	return (0);
}
