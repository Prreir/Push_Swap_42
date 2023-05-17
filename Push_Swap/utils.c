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

void	op_ss(t_data *data)
{
	int	tmp;
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

void	get_index(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->a.size)
	{
		j = 0;
		while (data->a.stack[i] != data->a.clone[j])
			j++;
		if (data->a.stack[i] == data->a.clone[j])
			data->a.index[i] = j + 1;
		i++;
	}
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
		data->a.index[i] = data->a.stack[i];
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
	get_index(data);
}
