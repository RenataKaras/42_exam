/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brackets.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 12:42:26 by rkaras        #+#    #+#                 */
/*   Updated: 2024/11/19 13:39:49 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */




// Assignment name : brackets 
// Expected files : *.c *.h 
// Allowed functions: write
// 
// Write a program that takes an undefined number of strings in arguments. For each argument, 
// the program prints on the standard output "OK" followed by a newline if the expression is 
// correctly bracketed, otherwise it prints "Error" followed by a newline.

// Symbols considered as 'brackets' are brackets '(' and ')', square brackets '[' and ']'and
// braces '{' and '}'. Every other symbols are simply ignored.

// An opening bracket must always be closed by the good closing bracket in the correct order.
// A string which not contains any bracket is considered as a correctly bracketed string.
// If there is no arguments, the program must print only a newline.
// Examples :

// $> ./brackets '(johndoe)' | cat -e

// OK$

// $> ./brackets '([)]' | cat -e

// Error$

// $> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e

// OK$

// OK$

// $> ./brackets | cat -e

// $

// $>

#include <stdbool.h>
#include <unistd.h>

bool	is_open_bracket(char ch)
{
	if (ch == '(' || ch == '[' || ch == '{')
		return (true);
	return (false);
}

bool	is_closed_bracket(char ch)
{
	if (ch == ')' || ch == ']' || ch == '}')
		return (true);
	return (false);
}

bool	match_check(char a, char b)
{
	if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
		return (true);
	return (false);
}

bool	bracket_check(char *str)
{
	int	i = 0;
	int	stack[1000];
	int	top = 0;

	while (str[i])
	{
		if (is_open_bracket(str[i]) == true)
		{
			stack[top] = str[i];
			top++;
		}
		if (is_closed_bracket(str[i]) == true)
		{
			if (top == 0 || match_check(stack[top - 1], str[i]) == false)
				return (false);
			else
				top--;
		}
		i++;
	}
	if (top != 0)
		return (false);
	return (true);
}



int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
		write (1, "\n", 1);
	while (argv[i])
	{
		if (bracket_check(argv[i]) == true)
			write (1, "OK\n", 3);
		else
			write (1, "Error\n", 6);
		i++;
	}
	return (0);
}

