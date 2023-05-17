# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugoncal <lugoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:46:53 by lugoncal          #+#    #+#              #
#    Updated: 2023/04/06 23:46:53 by lugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./Libft/libft.a

SRC = main.c utils.c check.c operators.c order.c Big_op.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(LIBFT):
		$(MAKE) -C ./Libft

$(NAME):	$(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
	$(MAKE) clean -C ./Libft
	rm -rf $(OBJ)

fclean:	clean
	$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re:	fclean all