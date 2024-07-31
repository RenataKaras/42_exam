/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/11 15:26:28 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/12 12:21:59 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int *ft_range(int start, int end)
{
	int *array;
	int size = 0;
	int i = 0;
	if (start > end)
		ft_range(end, start);
	size = end - start + 1;
	array = malloc(size * sizeof(int));
	if (array)
	{
		while (i < size)
		{
			array[i] = start;
			i++;
			start++;
		}
	}
	return (array);
}