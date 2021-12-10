/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:15:43 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/10 17:52:32 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

int	end_program(t_game *game)
{
	if (!game->player)
	{
		printf("\x1b[35m""\nCongratulations!!""\x1b[0m");
		printf("\x1b[35m"" You finished the game!!\n\n""\x1b[0m");
		printf("\x1b[32m""Can you do it again with less than %d moves??\n\n"
			"\x1b[0m", game->moves);
	}
	else
	{
		printf("\x1b[33m""\nAre you sure you don't want to play?\n\n""\x1b[0m");
		printf("\x1b[33m""The Bunny is hungry :(\n\n""\x1b[0m");
	}
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_tile_map(game->tile_map);
	exit(0);
}
