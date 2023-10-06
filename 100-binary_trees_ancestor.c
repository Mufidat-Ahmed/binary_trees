#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t **first_path = NULL, **second_path = NULL, *loc;
	const binary_tree_t *current = first;
	binary_tree_t **new_first_path, **new_second_path;
	size_t len1 = 0, len2 = 0;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}


	while (current != NULL)
	{
		new_first_path = (binary_tree_t **)realloc(first_path, (len1 + 1) * sizeof(binary_tree_t *));
		if (new_first_path == NULL)
		{
			free(first_path);
			return (NULL);
		}
		first_path = new_first_path;
		first_path[len1++] = (binary_tree_t *)current;
		current = current->parent;
	}
	current = second;
	while (current != NULL)
	{
		new_second_path = (binary_tree_t **)realloc(second_path, (len2 + 1) * sizeof(binary_tree_t *));
		if (new_second_path == NULL)
		{
			free(first_path);
			free(second_path);
			return (NULL);
		}
		second_path = new_second_path;
		second_path[len2++] = (binary_tree_t *)current;
		current = current->parent;
	}
	while (len1 > 0 && len2 > 0)
	{
		if (first_path[len1 - 1] != second_path[len2 - 1])
		{
			break;
		}
		len1--;
		len2--;
	}
	if (len1 == 0)
	{
		free(second_path);
		return ((binary_tree_t *)first);
	}
	else if (len2 == 0)
	{
		free(second_path);
		return ((binary_tree_t *)second);
	}
	loc = first_path[len1];
	free(first_path);
	free(second_path);
	return (loc);

}
