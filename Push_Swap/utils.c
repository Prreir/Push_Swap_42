/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:47:19 by lugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 23:47:19 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *data, int argc)
{
	data->a.stack = malloc(sizeof(int) * (argc - 1));
	data->a.clone = malloc(sizeof(int) * (argc - 1));
	data->a.size = 0;
	data->a.min = 0;
	data->a.max = 0;
	data->b.stack = malloc(sizeof(int) * (argc - 1));
	data->b.size = 0;
	data->b.min = 0;
	data->b.max = 0;
}

void	error_msg(t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	free(data->a.stack);
	free(data->a.clone);
	free(data->b.stack);
	free(data);
	exit (1);
}

long	ft_atoi_long(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

void	dup_sort(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i != data->a.size)
	{
		data->a.clone[i] = data->a.stack[i];
	}
	i = -1;
	while (++i != data->a.size)
	{
		j = i;
		while (++j != data->a.size)
		{
			if (data->a.clone[i] > data->a.clone[j])
			{
				tmp = data->a.clone[i];
				data->a.clone[i] = data->a.clone[j];
				data->a.clone[j] = tmp;
			}
		}
	}
	get_nums_radix(data);
}

void	get_nums_radix(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->a.size)
	{
		if (data->a.stack[i] == data->a.clone[j])
			data->a.stack[i] = j + 1;
		j = 0;
		while (data->a.stack[i] != data->a.clone[j])
			j++;
		i++;
	}
}
