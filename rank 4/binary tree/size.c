/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/21 16:15:10 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:16:51 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

int size_tree(t_tree *tree)
{
	if (!tree)
		return (0);
	return (1 + size_tree(tree->left) + size_tree(tree->right));
}