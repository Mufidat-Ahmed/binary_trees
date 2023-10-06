#include "binary_trees.h"

/**
 * find_min_val - Finds the node with the minimum value in a BST
 * @node: Pointer to the root node of the BST
 * Return: Pointer to the node with the minimum value
 */

bst_t *find_min_val(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = root->right;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = find_min_val(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
		if (root->right == NULL)
			return (root);
	}
	return (root);
}
