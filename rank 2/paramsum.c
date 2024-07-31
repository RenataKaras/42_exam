/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paramsum.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 19:16:53 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/22 19:22:39 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnmbr (int num)
{
	char digit;
	if (num / 10 > 0)
		putnmbr(num / 10);
	digit = num % 10 + '0';
	write (1, &digit, 1);
}



int main(int argc, char **argv)
{
	(void)argv;
	putnmbr(argc - 1);
	write (1, "\n", 1);
}



// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>