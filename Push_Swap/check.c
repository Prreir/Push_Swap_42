/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:46:34 by lugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 23:46:34 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getsizes_a(t_data *data)
{
	int		i;

	i = 0;
	data->a.min = data->a.stack[i];
	while (i < data->a.size)
	{
		if (data->a.min > data->a.stack[i])
			data->a.min = data->a.stack[i];
		i++;
	}
	i = 0;
	data->a.max = data->a.stack[i];
	while (i < data->a.size)
	{
		if (data->a.max < data->a.stack[i])
			data->a.max = data->a.stack[i];
		i++;
	}
}

void	checkdouble(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i != data->a.size)
	{
		j = i + 1;
		while (j != data->a.size)
		{
			if (data->a.stack[i] == data->a.stack[j])
				error_msg(data);
			j++;
		}
		i++;
	}
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

void	checkalpha(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (str[i] != 45 && str[i] != 43)
				error_msg(data);
		}
		i++;
	}
}

void	checkargs(int argc, char **argv, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->a.size = argc - 1;
	while (++i < data->a.size)
		checkalpha(argv[i], data);
	i = -1;
	j = 1;
	while (++i < data->a.size)
	{
		if (ft_atoi_long(argv[j]) > INT_MAX || ft_atoi_long(argv[j]) < INT_MIN)
			error_msg(data);
		data->a.stack[i] = ft_atoi_long(argv[j++]);
	}
	checkdouble(data);
	getsizes_a(data);
}
