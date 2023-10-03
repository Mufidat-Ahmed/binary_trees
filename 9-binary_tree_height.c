#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 or NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;
	const binary_tree_t *current = tree;

	if (tree == NULL)
	{
		return (0);
	}

	while (current != NULL)
	{
		height_left++;
		current = current->left;
	}

	while (current != NULL)
	{
		height_right++;
		current = current->right;
	}

	return ((height_left > height_right) ? height_left : height_right);
}
