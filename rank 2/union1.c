/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 15:42:14 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/13 17:05:36 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check (char *str, int ch, int delimiter)
{
	int i = 0;
	while (str[i] && (i < delimiter))
	{
		if (str[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
int main (int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		while (argv[1][i])
			i++;
		while (argv[2][j])
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0)
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}