/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 18:33:04 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/13 16:01:37 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int i = 0;
    int sign = 1;
    if (str[0] == '-')
	{
        sign = -1;
		i++;
	}
    while(str[i])
    {
        if (str[i]>= '0' && str[i] <= '9')
            result = result * str_base + (str[i] - '0');
    
        else if (str[i]>= 'a' && str[i] <= 'f')
            result = result * str_base + (str[i] - 'a' + 10) ;
        
        else if (str[i]>= 'A' && str[i] <= 'F')
            result = result * str_base + (str[i] - 'A' + 10);

        i++;
    }
    return (sign * result);
}

// #include<stdio.h>
// int main()
// {
//     char *s = "b";
//     printf("%d", ft_atoi_base(s, 16));

// }

// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);