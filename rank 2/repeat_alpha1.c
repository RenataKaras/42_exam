/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   repeat_alpha1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 15:42:40 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/12 15:50:26 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int ch, int index)
{
	while (index > 0)
	{
		write (1, &ch, 1);
		index--;
	}
}

void ft_alpha(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i], str[i] + 1 - 'A');
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i], str[i] + 1 - 'a');
		i++;
	}
}


int main (int argc, char **argv)
{
	if (argc == 2)
		ft_alpha(argv[1]);
	write (1, "\n", 1);
}