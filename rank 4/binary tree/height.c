/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   height.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/20 17:53:30 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:32:10 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

int height(t_tree *tree)
{
	if (!tree)
		return (-1);
	int height_left = height(tree->left);
	int height_right = height(tree->right);
	if (height_left > height_right)
		return (1 + height_left);
	else
		return (1 + height_right);
}
