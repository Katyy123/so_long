/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:41 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/29 17:26:51 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    char    **map;
    t_game  *game;
    
    if(valid_file(argc, argv[1] == -1))
        return (-1);
    game->tilemap = map_parse(argv[1], game);
    if (!map)
        return (-1);
    
}
