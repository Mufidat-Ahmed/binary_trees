#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @trees: pointer to the root node of the tree to count the number of leaves
 * Return: 0
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_left, leaf_right;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	leaf_left = binary_tree_leaves(tree->left);
	leaf_right = binary_tree_leaves(tree->right);
	
	return (leaf_left + leaf_right);
}
