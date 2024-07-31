/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 17:15:18 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/22 15:21:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check (char *str, int ch, int delimiter)
{
	int i = 0;
	while (str[i] && (i < delimiter || delimiter == -1))
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0 && check(argv[2], argv[1][i], -1) == 1)
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}

// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $