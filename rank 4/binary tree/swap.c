/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/21 16:06:27 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:09:09 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tree
{
	int value;
	struct s_tree *left;
	struct s_tree *right;
} t_tree;

void	tree_swap(t_tree *tree)
{
	if (!tree)
		return ;
	tree_swap(tree->left);
	tree_swap(tree->right);
	t_tree *temp;
	temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;
}