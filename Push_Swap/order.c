/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:35:04 by lugoncal          #+#    #+#             */
/*   Updated: 2023/05/13 20:31:50 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_data *data)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;
	int	k;

	max_bits = 0;
	num = data->a.size;
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < num)
		{
			k = data->a.stack[0];
			if (((k >> i) & 1) == 1)
				op_r(data->a.stack, data->a.size, "ra\n");
			else
				op_pb(data);
		}
		while (data->b.size != 0)
			op_pa(data);
	}
}
