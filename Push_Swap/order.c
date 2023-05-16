/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:35:04 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/16 14:25:27 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_data *data, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_num = size;
	max_bits = 0;
	while ((max_num >> ++max_bits) != 0)
	i = -1;
	while (++i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = data->a.stack[0];
			if (((num >> i) & 1) == 1)
				op_r(data->a.stack, data->a.size, "ra\n");
			else
				op_pb(data);
			j++;
		}
		while (data->b.size != 0)
			op_pa(data);
	}
}

void	ordernum5(t_data *data)
{
	int		i;

	i = 0;
	while (data->a.stack[0] && i < 2)
	{
		if (data->a.stack[0] != data->a.max && data->a.stack[0] != data->a.min)
			op_r(data->a.stack, data->a.size, "ra\n");
		else if (data->a.stack[0] == data->a.max || \
		data->a.stack[0] == data->a.min)
		{
			op_pb(data);
			i = i + 1;
		}
	}
	if (data->b.stack[0] != data->a.max)
		op_r(data->b.stack, data->b.size, "rb\n");
	getsizes_a(data);
	ordernum3(data);
	op_pa(data);
	op_r(data->a.stack, data->a.size, "ra\n");
	op_pa(data);
}

void	ordernum3(t_data *data)
{
	if (data->a.stack[0] != data->a.min && data->a.stack[2] == data->a.max)
		op_s(data->a.stack, "sa\n");
	else if (data->a.stack[0] == data->a.max && data->a.stack[2] == data->a.min)
	{
		op_s(data->a.stack, "sa\n");
		op_rr(data->a.stack, data->a.size, "rra\n");
	}
	else if (data->a.stack[0] == data->a.max && data->a.stack[2] != data->a.min)
		op_r(data->a.stack, data->a.size, "ra\n");
	else if (data->a.stack[0] == data->a.min && data->a.stack[2] != data->a.max)
	{
		op_s(data->a.stack, "sa\n");
		op_r(data->a.stack, data->a.size, "ra\n");
	}
	else if (data->a.stack[0] != data->a.max && data->a.stack[2] == data->a.min)
		op_rr(data->a.stack, data->a.size, "rra\n");
}
