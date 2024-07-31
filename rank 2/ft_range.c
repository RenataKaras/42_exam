/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/22 19:28:25 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/12 12:23:07 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int start, int end)
{
	int *array;
	int i = 0;
	int size;
	
	if (start > end)
		return(ft_range(end, start));
	size = end - start + 1;
	array = malloc(sizeof(int) * size);
	if (array)
	{
		while (i < size)
		{
			array[i] = start;
			start++;
			i++;
		}
	}
	return(array);	
}


// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.