/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:46:41 by lugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 23:46:41 by lugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"
# include "limits.h"

typedef struct s_stack{
	int		*stack;
	int		*clone;
	int		size;
	int		min;
	int		max;
}	t_stack;

typedef struct s_data{
	t_stack	a;
	t_stack	b;
}	t_data;

//order.c
void	order(t_data *data);

//operators.c
void	op_s(int *stack, char *msg);
void	op_pa(t_data *data);
void	op_pb(t_data *data);
void	op_r(int *stack, int size, char *msg);
void	op_rr(int *stack, int size, char *msg);

//utils.c
void	init(t_data *data, int argc);
void	error_msg(t_data *data);
long	ft_atoi_long(const char *str);
void	dup_sort(t_data *data);
void	get_nums_radix(t_data *data);

//check.c
void	getsizes_a(t_data *data);
void	checkdouble(t_data *data);
void	checkalpha(char *str, t_data *data);
void	checkargs(int argc, char **argv, t_data *data);

//main.c
void	ordernum3(t_data *data);
void	ordernum5(t_data *data);

#endif