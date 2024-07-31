/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   biggest_pal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 14:40:45 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/23 11:16:31 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	is_pal(char *str, int start, int len)
{
	int i = 0;
	while (i < len/2)
	{
		if (str[start + i] != str[start - i + len - 1])
			return (0);
		i++;
	}
	return (1);
}	

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return(i);
}

int	main (int argc, char **argv)
{
	int i = 0;
	int len;
	int start;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		while (i < len)
		{
			start = i;
			while (start >= 0)
			{
				if (is_pal(argv[1], start, len - i) == 1)
				{
					write (1, &argv[1][start], len-i);
					write(1, "\n",1);
					return (0);
				}
				start--;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}


// Assignment name  : biggest_pal
// Expected files   : *.c, *.h
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program named biggest_pal that takes a string as argument and prints the
// biggest palindrome included inside this string, followed by a newline.

// This string contains only lowercase characters.

// If there is two palindromes of the same length, you have to print the last one.

// If there is more or less than 1 argument, your program must print only a newline
// only.

// Exemples:

// $> biggest_pal "abcba"
// abcba
// $> biggest_pal "aaaaaaaaaabbcbbaaaa" | cat -e"
// aaaabbcbbaaaa
// $> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
// zeldaisaboyobasiadlez
// $> biggest_pal "aeibaabaammaabaalek"
// aabaammaabaa
// $> biggest_pal abeb qpinqwjobo qkmnwoiq

// $> biggest_pal

// $>