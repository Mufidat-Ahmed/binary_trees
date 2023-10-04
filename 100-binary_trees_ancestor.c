#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @firt:  pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_path[1000], *second_path[1000], *current, *loc;
	size_t len1 = 0, len2 = 0;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	current = (binary_tree_t *)first;
	while (current != NULL)
	{
		first_path[len1] = current;
		current = current->parent;
	}
	current = (binary_tree_t *)second;
	while (current != NULL)
	{
		second_path[len2] = current;
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
		return ((binary_tree_t *)first);
	}
	else if (len2 == 0)
	{
		return ((binary_tree_t *)second);
	}
	loc = first_path[len1];
	return (loc);

}
