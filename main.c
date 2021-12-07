/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:41 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/07 18:40:20 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map/map.h"

int main(int argc, char **argv)
{
    char    **map;
    t_game  *game;
    
    if(!valid_file(argc, argv[1]))
        return (-1);
    game->collects = 0;
    game->moves = 0;
    game->tile_map = map_parse(argv[1], game);
    if (game->tile_map == NULL)
        return (-1);
    if (!game_init(game))
        return (-1);
    mlx_hook(game->win, 2, (1L<<0), input, game);
    mlx_loop_hook(game->mlx, render, game);
    mlx_loop(game->mlx);
    return (0);
}
