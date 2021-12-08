/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:54:46 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/08 18:57:33 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../so_long.h"
# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

typedef struct s_map_check_data
{
	int     size_x;
	int     size_y;
	int     player;
	int     collect;
	int     exit;
	t_bool  rectangular;
	t_bool  border_walls;
	t_bool  valid_char;
}   t_map_check_data;

/* map_reader.c */
t_tile              **map_parse(char *file, t_game *game);
char	            **read_map(char *file);
int                 file_linecount(char *file);
int                 valid_file(int argc, char *file);

/* map_checker.c */
t_bool	            valid_map(char **map);
void	            check_border(char c, t_map_check_data *data, int x, int y);
void	            is_valid_char(char character, t_map_check_data *data);
void	            is_rectangular(char *row, t_map_check_data *data);
t_map_check_data    map_check_init(char **map);

/* map_checker_2.c */
t_bool              check_map_errors(t_map_check_data data);
void                count_chars(t_map_check_data *data, char c);

/* tile_map_gen.c */
t_tile              **gen_tile_map(char **map, t_game *game);
void                set_game(t_tile *tile, t_game *game);
void                set_tile(t_tile **tile_map, char c, int x, int y);
t_tile              **alloc_tile_map(char **map);

/* map_utils.c */
void                free_tile_map(t_tile **tile_map);

#endif
