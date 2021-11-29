/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:52:04 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/29 19:28:51 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map_check_data	map_check_init(t_map_check_data data, char **map)
{
	data.size_x = ft_strlen(map[0]);
	data.size_y = ft_chartable_linecount(map);
	data.point_x = 0;
	data.point_y = 0;
	data.player = FALSE;
	data.collect = FALSE;
	data.exit = FALSE;
	return (data);
}

check(t_map_check_data data, char **map)
{

}

int	valid_map(char **map)
{
	t_map_check_data	data;
	t_bool				valid;

	valid = TRUE;
	data = map_check_init(data, map);
	while (map[data.point_y])
	{
		if (ft_strlen(map[data.point_y]) != data.size_x)
			valid = error("map should be rectangular");
		while (map[data.point_y][data.point_x])
		{
			if (!check(data, map))
				valid = FALSE;
			data.point_x++;
		}
		data.point_y++;
	}
	return (valid);
}
