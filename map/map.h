/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:54:46 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/29 19:03:44 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../so_long.h"
# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

int     valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

typedef struct s_map_check_data
{
    int     size_x;
    int     size_y;
    int     point_x;
    int     point_y;
    t_bool  player;
    t_bool  collect;
    t_bool  exit;
}   t_map_check_data;

#endif
