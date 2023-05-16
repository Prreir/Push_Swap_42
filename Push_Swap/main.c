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

void	init(t_data *data, int argc)
{
	data->a.stack = malloc(sizeof(int) * (argc - 1));
	data->a.size = 0;
	data->a.min = 0;
	data->a.max = 0;
	data->b.stack = malloc(sizeof(int) * (argc - 1));
	data->b.size = 0;
	data->b.min = 0;
	data->b.max = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 2)
	{
		data = malloc(sizeof(t_data));
		init(data, argc);
		checkargs(argc, argv, data);
		if (argc - 1 == 3)
			ordernum3(data);
		else if (argc - 1 == 5)
			ordernum5(data);
		else
			order(data, data->a.size);
		free(data->a.stack);
		free(data->b.stack);
		free(data);
	}
	return (0);
}
