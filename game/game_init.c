/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:15:50 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/08 19:20:29 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	files_to_imgs(t_game *game)
{
	game->player_img = mlx_xpm_file_to_image(game->mlx, "images/bunny.xpm",
			&game->imgs_size_x, &game->imgs_size_y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/door.xpm",
			&game->imgs_size_x, &game->imgs_size_y);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "images/carrots.xpm",
			&game->imgs_size_x, &game->imgs_size_y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/tree.xpm",
			&game->imgs_size_x, &game->imgs_size_y);
	game->grass_img = mlx_xpm_file_to_image(game->mlx, "images/grass.xpm",
			&game->imgs_size_x, &game->imgs_size_y);
	if (!game->player_img || !game->exit_img || !game->collect_img
		|| !game->wall_img)
		return (error("mlx_xpm_file_to_image failed"));
	return (1);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error("mlx_init failed"));
	game->win = mlx_new_window(game->mlx, game->win_size_x,
			game->win_size_y, "Bunny game");
	if (!game->win)
		return (error("mlx_new_window failed"));
	if (!files_to_imgs(game))
		return (0);
	return (1);
}
