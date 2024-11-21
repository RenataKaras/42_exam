/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_number.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/20 17:13:37 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:24:24 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

typedef struct s_tree
{
	int	value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

// recursion
int	find_biggest(t_tree *tree)
{
	if (tree == NULL)
		return (INT_MIN);
	int max = tree->value;
	int left = find_biggest(tree->left);
	int right = find_biggest(tree->right);
	if (left > max)
		max = left;
	if (right > max)
		max = right;
	return (max);
}

