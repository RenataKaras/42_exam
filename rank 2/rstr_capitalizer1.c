/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rstr_capitalizer1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 15:51:41 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/12 16:20:58 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rstr_capitalizer(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] = str[i] - 'a' + 'A';
		write (1, &str[i], 1);
		i++;
	}
}


int main (int argc, char **argv)
{
	if (argc == 1)
		write (1, "\n", 1);
	else
	{
		int i = 1;
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write (1, "\n", 1);
			i++;
		}	
	}
}