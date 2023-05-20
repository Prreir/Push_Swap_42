/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:47:08 by lugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 23:47:08 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_s(int *stack, char *msg)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = stack[i];
	stack[i] = stack[i + 1];
	stack[i + 1] = tmp;
	ft_putstr_fd(msg, 1);
}

void	op_pa(t_data *data)
{
	int		i;

	data->a.size++;
	i = data->a.size - 1;
	while (i > 0)
	{
		data->a.stack[i] = data->a.stack[i - 1];
		i--;
	}
	data->a.stack[0] = data->b.stack[0];
	i = 0;
	while (i < data->b.size - 1)
	{
		data->b.stack[i] = data->b.stack[i + 1];
		i++;
	}
	data->b.size--;
	ft_putstr_fd("pa\n", 1);
}

void	op_pb(t_data *data)
{
	int		i;

	data->b.size++;
	i = data->b.size - 1;
	while (i > 0)
	{
		data->b.stack[i] = data->b.stack[i - 1];
		i--;
	}
	data->b.stack[0] = data->a.stack[0];
	i = 0;
	while (i < data->a.size - 1)
	{
		data->a.stack[i] = data->a.stack[i + 1];
		i++;
	}
	data->a.size--;
	ft_putstr_fd("pb\n", 1);
}

void	op_r(int *stack, int size, char *msg)
{
	int		tmp;
	int		i;

	i = -1;
	while (++i < size - 1)
	{
		tmp = stack[i];
		stack[i] = stack[i + 1];
		stack[i + 1] = tmp;
	}
	ft_putstr_fd(msg, 1);
}

void	op_rr(int *stack, int size, char *msg)
{
	int		tmp;
	int		i;

	i = size;
	while (--i != 0)
	{
		tmp = stack[i];
		stack[i] = stack[i - 1];
		stack[i - 1] = tmp;
	}
	ft_putstr_fd(msg, 1);
}
