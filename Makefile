# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 17:00:59 by cfiliber          #+#    #+#              #
#    Updated: 2021/11/19 13:28:37 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB_PATH = ./libft/

LIB = $(LIB_PATH)libft.a

SRCS = \
		so_long.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I libft -Imlx # ho aggiunto -Imlx per includere minilibX 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: subsystem $(NAME)

subsystem:
	make all -C $(LIB_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIB)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
