/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:15:50 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/04 18:32:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    game_init(t_game *game)
{
    game->mlx = mlx_init();
    game->win_size_x = x * IMG_SIZE;
    
    game->win = mlx_new_window(game->mlx, )
}
