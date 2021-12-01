/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:29:56 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/01 18:32:34 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool  check_map_errors(t_map_check_data data)
{
    t_bool  valid;

    valid = TRUE;
    printf("data.player = %d, data.exit = %d, data.collect = %d (in check_map_errors())\n", data.player, data.exit, data.collect);//togli
    printf("data.border_walls in check_map_errors()= %d\n", data.border_walls);//togli
    if (data.player != 1 || data.exit != 1 || data.collect == 0)
        valid = error("map must have one 'P', one 'E' and at least one 'C'");
    if (data.rectangular == FALSE)
        valid = error("map must be rectangular");
    if (data.border_walls == FALSE)
        valid = error("map must be surrounded by walls");
    if (data.valid_char == FALSE)
        valid = error("invalid character");
    return (valid);
}

void    count_chars(t_map_check_data *data, char c)
{
    if (c == 'P')
        data->player++;
    if (c == 'E')
        data->exit++;
    if (c == 'C')
        data->collect++;
}