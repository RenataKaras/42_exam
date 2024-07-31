/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_anagram1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/13 15:11:14 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/13 15:33:34 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int is_anagram(char *a, char *b)
{
	int i = 0;
	int ch[127] = {0};
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