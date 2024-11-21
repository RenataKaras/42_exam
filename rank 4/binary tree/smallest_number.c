/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallest_number.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/21 16:09:33 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:14:35 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

int	smallest(t_tree *tree)
{
	if (!tree)
		return (INT_MAX);
	int min = tree->value;
	int left = smallest(tree->left);
	int right = smallest(tree->right);
	if (left < min)
		min = left;
	if (right < min)
		min = right;
	return (min);
}