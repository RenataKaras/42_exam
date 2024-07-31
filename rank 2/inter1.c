/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 14:42:12 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 15:00:20 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(char *str, int ch, int delimiter)
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

int main (int argc, char **argv)
{
	int i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0 && check(argv[2], argv[1][i], -1) == -1)
				write (1, &argv[1][i], 1);
			i++;
		}	
	}
	write (1, "\n", 1);
}