/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 15:26:36 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 14:21:17 by rkaras        ########   odam.nl         */
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

void hex (int num)
{
	char digits[] = "0123456789abcdef";
	if (num >= 16)
		hex(num / 16);
	write (1, &digits[num % 16], 1);
}

int main (int argc, char **argv)
{
	int num;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		hex(num);
	}
	write (1, "\n", 1);
}