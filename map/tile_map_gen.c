/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_map_gen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:21:51 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/04 18:34:58 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_tile  **alloc_tile_map(char **map)
{
    t_tile  **tile_map;
    int     i;

    tile_map = malloc(sizeof(t_tile *) * ft_char_mtx_linecount(map) + 1);
    if (!tile_map);
        return (NULL);
    i = 0;
    while (map[i])
    {
        tile_map[i] = malloc(sizeof(t_tile) * ft_strlen(map[i]) + 1);
        if (!tile_map[i])
        {
            while (i > 0)    
                free(tile_map[--i]);
            free_tile_map(tile_map);
            return (NULL);
        }
        i++;
    }
    return (tile_map);
}

void    set_tile(t_tile **tile_map, char c, int x, int y)
{   
    if (c == 'P')
        tile_map[y][x].type = PLAYER;
    else if (c == 'E')
        tile_map[y][x].type = EXIT;
    else if (c == 'C')
        tile_map[y][x].type = COLLECTABLE;
    else if (c == '0')
        tile_map[y][x].type = EMPTY;
    else if (c == '1')
        tile_map[y][x].type = WALL;
    tile_map[y][x].position_x = x * IMG_SIZE;
    tile_map[y][x].position_y = y * IMG_SIZE;
    if (y != 0)
        tile_map[y][x].up = &tile_map[y - 1][x];
    if (tile_map[y + 1])
        tile_map[y][x].down = &tile_map[y + 1][x];
    if (x != 0)
        tile_map[y][x].left = &tile_map[y][x - 1];
    tile_map[y][x].right = &tile_map[y][x + 1];//se non c'è una tile a destra, allora punta a NULL ('\0')
}

void    set_game(t_tile *tile, t_game *game)
{
    if (tile->type == PLAYER)
        game->player = tile;
    else if (tile->type == COLLECTABLE)
        game->collects++;
}

t_tile  **gen_tile_map(char **map, t_game *game)
{
    t_tile  **tile_map;
    int     x;
    int     y;

    tile_map = alloc_tile_map(map);
    if (!tile_map)
        return (NULL);
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            set_tile(tile_map, map[y][x], x, y);
            set_game(&tile_map[y][x], game);//devo dargli l'indirizzo di tile_map perchè poi devo salvarlo dentro la struct game in caso di Player
            x++;
        }
        tile_map[y][x].type = 0;//vedere se serve
        y++;
    }
    tile_map[y] = NULL;
    game->win_size_x = x * IMG_SIZE;//moltiplico il numero delle caselle della mappa per il numero di pixel in ogni casella
	game->win_size_y = y * IMG_SIZE;
    return (tile_map);
}
