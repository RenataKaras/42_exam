/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   repeat_alpha.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/15 10:26:13 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/22 14:42:55 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void ft_putchar(int ch, int index)
{
	while (index > 0)
	{
		write (1, &ch, 1);
		index--;
	}
}


void	ft_alpha(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i], str[i] + 1 - 'a');
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i], str[i] + 1 - 'A');
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_alpha (argv[1]);
	write (1, "\n", 1);
}

// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>