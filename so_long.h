/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:01:40 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/04 18:17:39 by cfiliber         ###   ########.fr       */
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

/* Errors */
# define MLX_ERROR -1

/* Size of every character */
# define IMG_SIZE 90

/* Tiles types*/
typedef enum e_tile_type
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTABLE = 'C'	
}	t_tile_type;

/* Boolean values */
typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

/* Struct for each tile. Tiles are arranged in a matrix */
typedef struct	s_tile
{
	t_tile_type		type;
	int				position_x;
	int				position_y;
	struct s_tile	*up;//puntatore alla casella (tile) superiore
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct	s_panel 
{
	void	*pointer;
	char	*pix_address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_panel;

typedef struct	s_game 
{
	void		*mlx;
	void		*win;
	int			win_size_x;
	int			win_size_y;
	t_tile		**tile_map;
	t_tile		*player;
	void		*player_img;
	int			collects;//number of collectables
	int			moves;
	int			img_size_x;
	int			img_size_y;
	void		*wall_img;
	void		*collect_img;
	void		*door_img;
	void		*panel;//puntatore all'immagine
}	t_game;

/* main.c */
int main(int argc, char **argv);


/* errors.c */
int		error(char *message);
void    *null_error(char *message);
void    print_warning(char *message);

#endif
