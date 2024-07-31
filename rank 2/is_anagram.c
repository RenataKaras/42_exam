/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_anagram.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/14 13:54:55 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/22 16:31:26 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int is_anagram(char *a, char *b)
{
	int i = 0;
	int ch [127] = {0};

	while (a[i])
	{
		ch[(int)a[i]] += 1;
		i++;
	}
	i = 0;
	while (b[i])
	{
		ch[(int)b[i]] -= 1;
		i++;
	}
	i = 0;
	while (i < 127)
	{
		if (ch[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char a[] = "abca";
	char b[] = "bcab";
	printf("%i\n", is_anagram(a, b));
	return (0);
}

// Assignment name  : is_anagram
// Expected files   : is_anagram.c
// Allowed functions:
// --------------------------------------------------------------------------------

// ALERT: OPTIMIZED SOLUTION REQUIRED.

// An anagram is a sequence of characters formed by rearranging the letters of
// another sequence, such as 'cinema', formed from 'iceman'.

// Given two strings as parameters, create a function able to tell whether or
// not the first string is an anagram of the second.

// The function must be declared as follows:

// int        is_anagram(char *a, char *b);

// Considerations:

// - Be careful: the naive solution won't work on our big input, you have to
// find an optimized solution which will run in O(sa + sb) time (where sa is
// the length of a and sb length of b).
// - Our tested string will always be a sequence of ascii characters between 32
// and 126 inclusive.
// - The bigger test we will do is on 2 sequences of 1.000.000 characteres each.
// It should run in less than 2 seconds.

// Example 1:

// a='abcdef'
// b='fabcde'

// In this case, these two strings are anagrams, your function should return 1.

// Example 2:

// a='.123?.'
// b='?321..'

// In this case, these two strings are anagrams, your function should return 1.

// Example 3:

// a='abca'
// b='bcab'

// In this case, these two strings are not anagrams, your function should return 0.