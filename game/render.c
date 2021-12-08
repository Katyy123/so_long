/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:41:13 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/08 18:56:45 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    put_image(t_tile tile, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->grass_img, x, y);
	if (tile.type == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x, y);
}

int render(t_game *game)
{
	t_tile  tile;
	int     x;
	int     y;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (game->tile_map[y])
	{
		x = 0;
		while (game->tile_map[y][x].type)
		{
			tile = game->tile_map[y][x];
			put_image(tile, game, tile.position_x, tile.position_y);
			x++;
		}
		y++;
	}
	return(1);
}
