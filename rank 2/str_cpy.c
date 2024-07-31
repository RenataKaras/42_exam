/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_cpy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 14:19:21 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/22 14:22:55 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char *strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:

// char    *ft_strcpy(char *s1, char *s2);