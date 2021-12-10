/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:04 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/10 18:12:43 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map_check_data	map_check_init(char **map)
{
	t_map_check_data	data;

	data.size_x = ft_strlen(map[0]);
	data.size_y = ft_char_mtx_linecount(map);
	data.player = 0;
	data.collect = 0;
	data.exit = 0;
	data.rectangular = TRUE;
	data.border_walls = TRUE;
	data.valid_char = TRUE;
	return (data);
}

void	is_rectangular(char *row, t_map_check_data *data)
{
	if (ft_strlen(row) != data->size_x)
		data->rectangular = FALSE;
}

void	is_valid_char(char character, t_map_check_data *data)
{
	if (character != '0' && character != '1' && character != 'P'
		&& character != 'E' && character != 'C')
		data->valid_char = FALSE;
}

void	check_border(char c, t_map_check_data *data, int x, int y)
{
	if (x == 0 || y == 0 || x == data->size_x - 1 || y == data->size_y - 1)
	{
		if (c != '1')
			data->border_walls = FALSE;
	}
}

t_bool	valid_map(char **map)
{
	t_map_check_data	data;
	t_bool				valid;
	int					x;
	int					y;

	valid = TRUE;
	y = 0;
	data = map_check_init(map);
	while (map[y])
	{
		is_rectangular(map[y], &data);
		x = 0;
		while (map[y][x])
		{
			is_valid_char(map[y][x], &data);
			check_border(map[y][x], &data, x, y);
			count_chars(&data, map[y][x]);
			x++;
		}
		y++;
	}
	check_map_size(x, y);
	valid = check_map_errors(data);
	return (valid);
}
