/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Big_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:53:51 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/17 09:02:35 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_r500(t_data *data, int size)
{
	int		tmp;
	int		i;

	i = -1;
	while (++i < size - 1)
	{
		tmp = data->a.stack[i];
		data->a.stack[i] = data->a.stack[i + 1];
		data->a.stack[i + 1] = tmp;
	}
	i = -1;
	while (++i < size - 1)
	{
		tmp = data->a.index[i];
		data->a.index[i] = data->a.index[i + 1];
		data->a.index[i + 1] = tmp;
	}
	ft_putstr_fd("ra\n", 1);
}

void	op_pb500(t_data *data)
{
	int		i;

	data->b.size++;
	i = data->b.size - 1;
	while (i > 0)
	{
		data->b.stack[i] = data->b.stack[i - 1];
		data->b.index[i] = data->b.index[i - 1];
		i--;
	}
	data->b.stack[0] = data->a.stack[0];
	data->b.index[0] = data->a.index[0];
	i = 0;
	while (i < data->a.size - 1)
	{
		data->a.stack[i] = data->a.stack[i + 1];
		data->a.index[i] = data->a.index[i + 1];
		i++;
	}
	data->a.size--;
	ft_putstr_fd("pb\n", 1);
}

void	op_pa500(t_data *data)
{
	int		i;

	data->a.size++;
	i = data->a.size - 1;
	while (i > 0)
	{
		data->a.stack[i] = data->a.stack[i - 1];
		data->a.index[i] = data->a.index[i - 1];
		i--;
	}
	data->a.stack[0] = data->b.stack[0];
	data->a.index[0] = data->b.index[0];
	i = 0;
	while (i < data->b.size - 1)
	{
		data->b.stack[i] = data->b.stack[i + 1];
		data->b.index[i] = data->b.index[i + 1];
		i++;
	}
	data->b.size--;
	ft_putstr_fd("pa\n", 1);
}
