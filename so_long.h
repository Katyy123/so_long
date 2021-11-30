/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:01:40 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/30 19:09:21 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Libraries */
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

/* Keycodes */
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53

/* Tiles */
# define EMPTY '0'
# define WALL '1'
# define COLLECTABLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

/* Errors */
#define MLX_ERROR -1

/* Size of every character */
# define IMG_SIZE 90

/* Boolean values */
typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Struct for each tile */
typedef struct	s_tile
{
	char			type;
	int				position_x;
	int				position_y;
	struct s_tile	*up;//puntatore alla casella (tile) superiore
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	int		moves;
	int		collects;
	t_tile	**tilemap;
}				t_game;

/* main.c */
int main(int argc, char **argv);


/* errors.c */
int		error(char *message);
void    *null_error(char *message);
void    print_warning(char *message);

#endif
