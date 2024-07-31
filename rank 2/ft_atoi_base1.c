/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 12:00:02 by rkaras        #+#    #+#                 */
/*   Updated: 2024/06/14 14:06:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(const char *str, int str_base)
{
	int sign = 1;
	int result;
	int i = 0;

	if (str[i] == '-')
		sign = -1;
	i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * str_base + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * str_base + (str[i] - 'A' + 10);
		i++;
	}
	return (result * sign);
}
