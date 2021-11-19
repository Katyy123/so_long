/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:29:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/19 15:15:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Dolphin game");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_loop(mlx);

}
