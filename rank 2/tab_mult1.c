/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tab_mult1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/13 14:43:15 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 14:35:52 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int atoi (char *str)
{
	int num = 0;
	int i = 0;
	while (str[i])
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num);
}

// void putchar (int ch)
// {
// 	write (1, &ch, 1);
// }


void putnmbr(int num)
{
	char digit;
	if (num / 10 > 0)
		putnmbr(num / 10);
	digit = num % 10 + '0';
	write (1, &digit, 1);
}


int main (int argc, char **argv)
{
	int num;
	int i = 1;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		while (i <= 9)
		{
			putnmbr(i);
			write (1, " x ", 3);
			putnmbr(num);
			write (1, " = ", 3);
			putnmbr(num * i);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}