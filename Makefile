# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 17:00:59 by cfiliber          #+#    #+#              #
#    Updated: 2021/11/30 18:56:04 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB_PATH = ./libft/
LIB = $(LIB_PATH)libft.a

SRCS = $(MAIN_SRC) $(SRC_GNL) $(SRC_MAP)

MAIN_SRC = main.c errors.c

GNL = get_next_line.c
SRC_GNL = $(addprefix gnl/, $(GNL))

MAP = map_reader.c map_checker.c map_checker_2.C
SRC_MAP = $(addprefix map/, $(MAP))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I libft -Imlx #-fsanitize=address# ho aggiunto -Imlx per includere minilibX 

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: subsystem $(NAME)

subsystem:
	make all -C $(LIB_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIB)
	echo "To start the game, type "./so_long <map_file>".\nYou can choose one of theese maps:\n "map1.ber"  "map2.ber""

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
