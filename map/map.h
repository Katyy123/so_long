/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:54:46 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/01 11:25:21 by cfiliber         ###   ########.fr       */
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
int                 valid_file(int argc, char *file);
int                 file_linecount(char *file);
char	            **read_map(char *file);
char                **map_parse(char *file);

/* map_checker.c */
t_map_check_data	map_check_init(char **map);
void	            is_rectangular(char *row, t_map_check_data *data);
void	            is_valid_char(char character, t_map_check_data *data);
void	            check_border(char c, t_map_check_data *data, int x, int y);
t_bool	            valid_map(char **map);

/* map_checker_2.c */
t_bool  check_map_errors(t_map_check_data data);
void    count_chars(t_map_check_data *data, char c);

#endif
