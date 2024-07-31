/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 14:48:10 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 14:42:36 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int strlen (char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_pal(char *str, int start, int len)
{
	int i = 0;
	while (i < len / 2)
	{
		if (str[start + i] != str[start - i + len -1])
			return (0);
		i++;
	}
	return (1);
}


int main (int argc, char **argv)
{
	int start;
	int i = 0;
	int len;
	if (argc == 2)
	{
		len = strlen(argv[1]);
		while (i < len)
		{
			start = i;
			while (start >= 0)
			{
				if (is_pal(argv[1], start, len - i) == 1)
				{
					write (1, &argv[1][start], len - i);
					write (1, "\n", 1);
					return(0);
				}
				start--;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}