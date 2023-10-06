#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 * @tree:  pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *current;
	size_t queue_size = 1, front = 0, back = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return;
	queue[back++] = (binary_tree_t *)tree;
	while (front < back)
	{
		current = queue[front++];
		func(current->n);
		if (current->left != NULL)
		{
			if (back >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue, queue_size * sizeof(binary_tree_t *));
				if (queue == NULL)
					return;
			}
			queue[back++] = current->left;
		}
		if (current->right != NULL)
		{
			if (back >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue, queue_size * sizeof(binary_tree_t *));
				if (queue == NULL)
					return;
			}
			queue[back++] = current->right;
		}
	}
	free(queue);
}
