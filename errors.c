/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:15:40 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/10 17:50:38 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map/map.h"

int	error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	return (NULL);
}

void	print_warning(char *message)
{
	printf("\x1b[33m""Warning:\n%s\n""\x1b[0m", message);
}

int	exit_error(char *message, t_game *game)
{
	printf("\x1b[31m""Error:\n%s\n""\x1b[0m", message);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free_tile_map(game->tile_map);
	exit(-1);
}
