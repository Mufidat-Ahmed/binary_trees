#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *current;
	size_t queue_size = 0, front = 0, back = 0;
	int flag = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);
	queue[back++] = (binary_tree_t *)tree;
	while (front < back)
	{
		current = queue[front++];
		if (current == NULL)
			flag = 1;
		else
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			if (back >= queue_size)
			{
				queue_size = back * 2;
				queue = realloc(queue, queue_size * sizeof(binary_tree_t *));
				if (queue == NULL)
					return (0);
			}
			queue[back++] = current->left;
			queue[back++] = current->right;
		}
	}
	free(queue);
	return (1);
}
