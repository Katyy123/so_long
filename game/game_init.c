/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:15:50 by cfiliber          #+#    #+#             */
/*   Updated: 2021/12/07 15:14:38 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int files_to_imgs(t_game *game)
{
    char    *player_img_path = "../images/rabbit.xpm";
    char    *exit_img_path = "../images/door_with_stones.xpm";
    char    *collect_img_path = "../images/carrots.xpm";
    char    *wall_img_path = "../images/tree.xpm";

    game->player_img = mlx_xpm_file_to_image(game->mlx, player_img_path,
        game->imgs_size_x, game->imgs_size_y);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, exit_img_path,
        game->imgs_size_x, game->imgs_size_y);
    game->collect_img = mlx_xpm_file_to_image(game->mlx, collect_img_path,
        game->imgs_size_x, game->imgs_size_y);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, wall_img_path,
        game->imgs_size_x, game->imgs_size_y);
    if (!game->player_img || !game->exit_img || !game->collect_img ||
        !game->wall_img)
        return (error("mlx_xpm_file_to_image failed"));
    return (1);
}

void    color_grass(t_grass *grass, int color, t_game *game)
{
    char    *dst_pix;
    int     x;
    int     y;

    y = 0;
    while (y < game->win_size_y)
    {
        x = 0;
        while (x < game->win_size_x)
        {
            dst_pix = grass->addr + (y * grass->line_length +
                x * (grass->bits_per_pix/8));
            *(unsigned int *)dst_pix = color;
            x++;
        }
        y++;
    }
}

int    create_trgb_color(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

void    *create_grass_img(t_game *game)
{
    t_grass grass;
    int     color;
    
    grass.grass = mlx_new_image(game->mlx, game->win_size_y, game->win_size_x);
    if (!grass.grass)
        return (error("mlx_new_image failed"));
    grass.addr = mlx_get_data_addr(grass.grass, &grass.bits_per_pix,
        &grass.line_length, &grass.endian);
    if (!grass.addr)
        return (error("mlx_get_data_addr failed"));
    color = create_trgb_color(0x00, 0xB9, 0xD2, 0x96);
    color_grass(&grass, color, game);
    return (grass.grass);
}

int game_init(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return(error("mlx_init failed"));
    game->win = mlx_new_window(game->mlx, game->win_size_y,
        game->win_size_x, "Little Rabbit");//ho tolto + img_size/2
    if (!game->win)
        return(error("mlx_new_window failed"));
    //mlx_hook(game->win, 17, 0, end_program, game);//17 event: DestroyNotify  //end_program frees tile_map //vedere cosa succede se lo tolgo
    if (!files_to_imgs(game))
        return (0);
    game->grass = create_grass_img(game);
    if (!game->grass)
        return (0);
    return (1);
}

