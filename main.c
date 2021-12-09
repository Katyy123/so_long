/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:35:41 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/09 19:02:54 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map/map.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (!valid_file(argc, argv[1]))
		return (-1);
	game.collects = 0;
	game.moves = 0;
	game.tile_map = map_parse(argv[1], &game);
	if (game.tile_map == NULL)
		return (-1);
	if (!game_init(&game))
		return (-1);
	mlx_hook(game.win, 2, (1L << 0), input, &game);
	mlx_hook(game.win, 17, 0, end_program, &game);//collega x della finestra a end_program
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
