/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/20 17:38:40 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:28:16 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

t_tree	*find_num(t_tree *tree, int num)
{
	if (!tree)
		return (NULL);
	if (tree->value == num)
		return(tree);
	if (tree->value > num)
		return (find_num(tree->left, num));
	else
		return (find_num(tree->right, num));
	}
