/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:46:20 by lugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 23:46:20 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 2)
	{
		data = malloc(sizeof(t_data));
		init(data, argc);
		checkargs(argc, argv, data);
		dup_sort(data);
		if (argc - 1 == 3)
			ordernum3(data);
		else if (argc - 1 == 5)
			ordernum5(data);
		else
			order(data);
		free(data->a.stack);
		free(data->a.clone);
		free(data->b.stack);
		free(data);
	}
	return (0);
}
