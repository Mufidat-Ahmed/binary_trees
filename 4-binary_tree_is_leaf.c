#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: checks if a node is a leaf
 * Return: checks if a node is a leaf
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	return (node->left == NULL && node->right == NULL);
}
