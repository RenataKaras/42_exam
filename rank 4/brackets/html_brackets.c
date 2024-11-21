/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   html_brackets.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 12:53:11 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/21 16:49:04 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : html_validator
// Expected files   : *.c
// Allowed functions: write, malloc, strncmp, strncpy, free
// --------------------------------------------------------------------------------

// Write a program that takes a strings as argument and checks the html tags. 
// You don't need to know html to do this assignment.
// Your program must return a 0 for valid input and prints on the standard output "OK" followed by a newline
// if the expression is correctly bracketed, otherwise it returns 1 and prints "KO" followed by
// a newline.

// HTML opening tags look like this:
// <something> and closing tags like this </something>

// An opening tag must always be closed by the good closing tag in the
// correct order. 

// If there is no arguments, the program must print only a newline.

// Examples :

// $> ./html_validator '<b><blue></blue></b>'; echo $?
// 0

// $> ./html_validator '<b><blue></b></blue>'; echo $?
// 1

// $> ./html_validator '<blue attribute="bladiebla"></blue>'; echo $?
// 0

// $> ./html_validator '<img bladiebla><blue></blue>'; echo $?
// 0

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int tag_validator(char *str)
{
	char **stack;
	char *temp;
	int j = 0;
	int i = 0;
	int start;

	stack = malloc(sizeof(char *) * 100);
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] != '/')
		{
			start = i + 1;
			while (str[i] != '>' && str[i] != ' ')
				i++;
			j++;
			stack[j] = malloc(sizeof(char) * i - start + 1);
			strncpy(stack[j], str + start, i - start);
			stack[j][i - start] = '\0';
			if (strncmp(stack[j], "img", 3) == 0)
			{
				free(stack[j]);
				j--;
			}
		}
		else if (str[i] == '<' && str[i + 1] == '/')
		{
			start = i + 2;
			while (str[i] != '\0' && str[i] != '>')
				i++;
			temp = malloc(sizeof(char) * i - start + 1);
			strncpy(temp, str + start, i - start);
			temp[i - start] = '\0';
			if (stack[j] && strncmp(stack[j], temp, ft_strlen(temp)) == 0)
			{
				free(stack[j]);
				j--;
			}
			else
			{
				write (1, "KO\n", 3);
				return (1);
			}
		}
		i++;
	}
	write (1, "OK\n", 3);
	return (0);
}

int main (int argc, char **argv)
{
	if (argc == 1)
		write (1, "\n", 1);
	return (tag_validator(argv[1]));
}
