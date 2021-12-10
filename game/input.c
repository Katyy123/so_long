/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:23:32 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/10 17:56:39 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	move(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
	{
		tile->type = PLAYER;
		game->player->type = EMPTY;
		game->player = tile;
	}
	else if (tile->type == COLLECTABLE)
	{
		tile->type = PLAYER;
		game->player->type = EMPTY;
		game->player = tile;
		game->collects--;
	}
	else if (tile->type == EXIT && game->collects == 0)
	{
		game->player->type = EMPTY;
		game->player = NULL;
		end_program(game);
	}
	else
		return (FALSE);
	return (TRUE);
}

int	input(int key, t_game *game)
{
	t_bool	moved;

	moved = FALSE;
	if (key == KEY_ESC)
		end_program(game);
	else if (key == KEY_W)
		moved = move(game, game->player->up);
	else if (key == KEY_S)
		moved = move(game, game->player->down);
	else if (key == KEY_A)
		moved = move(game, game->player->left);
	else if (key == KEY_D)
		moved = move(game, game->player->right);
	else
		return (0);
	if (moved)
	{
		game->moves++;
		printf("Moves: %d\n", game->moves);
	}
	return (1);
}
