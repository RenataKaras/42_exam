/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 18:33:15 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/14 19:02:53 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

int atoi(char *str)
{
	int num = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10;
			num = num + (str[i] - '0');
		}
		i++;
	}
	return(num);
}

void hex (int num)
{
	char digits[] = "0123456789abcdef";

	if (num >= 16)
		hex(num / 16);
	write (1, &digits[num % 16], 1);
}

int main(int argc, char **argv)
{
	int num;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		hex(num);
	}
	write (1, "\n", 1);
}

// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $