/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:04:35 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/08 18:57:20 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    free_tile_map(t_tile **tile_map)
{
	int i;

	i = 0;
	while (tile_map[i])
		free(tile_map[i++]);
	free(tile_map);
}
