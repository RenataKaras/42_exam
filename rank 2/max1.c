/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max1.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:07:36 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/12 12:09:16 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int max (int *tab, unsigned int len)
{
	int max;
	int i = 0;

	max = tab[i];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}