/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tab_mult.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 18:08:11 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/13 14:56:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	atoi(char *str)
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

void ft_putchar(int ch)
{
	write (1, &ch, 1);
}

void putnbr(int nb)
{
	if (nb / 10 > 0)
		putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}


int main (int argc, char **argv)
{
	int i = 1;
	int num;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		while (i <= 9)
		{
			putnbr(i);
			write (1, " x ", 3);
			putnbr(num);
			write (1, " = ", 3);
			putnbr(i * num);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}



// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>