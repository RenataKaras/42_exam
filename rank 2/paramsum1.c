/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paramsum1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:33:26 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 14:14:31 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putchar(int ch)
{
	write (1, &ch, 1);
}

void putnmbr(int num)
{
	if (num / 10 > 0)
		putnmbr(num / 10);
	putchar(num % 10 + '0');
}

int main (int argc, char **argv)
{
	(void)argv;
	putnmbr(argc - 1);
	write (1, "\n", 1);
}