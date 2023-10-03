#include "binary_trees.h"

/**
 * binary_tree_is_height - calculate the height of a binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: 0
 */
int binary_tree_is_height(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
	{
		return (0);
	}
	height_left = binary_tree_is_height(tree->left);
	height_right = binary_tree_is_height(tree->right);
	return (1 + (height_left > height_right) ? height_left : height_right);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;
	int perfect_left, perfect_right;

	if (tree == NULL)
	{
		return (0);
	}
	height_left = binary_tree_is_height(tree->left);
	height_right = binary_tree_is_height(tree->right);
	if (height_left == height_right)
	{
		perfect_left = binary_tree_is_perfect(tree->left);
		perfect_right = binary_tree_is_perfect(tree->right);

		return (perfect_left && perfect_right);
	}
	return (0);
}
