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

void	error_msg(t_data *data)
{
	ft_putstr_fd("Error\n", 1);
	free(data->a.stack);
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

void	op_ss(t_data *data)
{
	int tmp;
	int	i;

	i = 0;
	tmp = data->a.stack[i];
	data->a.stack[i] = data->a.stack[i + 1];
	data->a.stack[i + 1] = tmp;
	tmp = data->b.stack[i];
	data->b.stack[i] = data->b.stack[i + 1];
	data->b.stack[i + 1] = tmp;
	ft_putstr_fd("ss\n", 1);
}

void	op_rr2(t_data *data)
{
	int		tmp;
	int		i;

	i = -1;
	while (++i < data->a.size - 1)
	{
		tmp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[i + 1];
		data->a.stack[i + 1] = tmp;
	}
	i = -1;
	while (++i < data->b.size - 1)
	{
		tmp = data->b.stack[i];
		data->b.stack[i] = data->b.stack[i + 1];
		data->b.stack[i + 1] = tmp;
	}
	ft_putstr_fd("rr\n", 1);
}

void	op_rrr(t_data *data)
{
	int		tmp;
	int		i;

	i = data->a.size;
	while (--i != 0)
	{
		tmp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[i - 1];
		data->a.stack[i - 1] = tmp;
	}
	i = data->b.size;
	while (--i != 0)
	{
		tmp = data->b.stack[i];
		data->b.stack[i] = data->b.stack[i - 1];
		data->b.stack[i - 1] = tmp;
	}
	ft_putstr_fd("rrr\n", 1);
}