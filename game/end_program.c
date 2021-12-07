/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:15:43 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/07 15:16:19 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

int end_program(t_game *game)
{
    mlx_destroy_display(game->mlx);//per usarla devo includere mlx folder //vedi se serve anche free all the images
    mlx_destroy_window(game->mlx, game->win);
    free(game->mlx);
    free_tile_map(game->tile_map);//vedi se serve aggiungere tile_map = NULL
    exit(0);
}
