/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:29:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/20 18:37:52 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	key_hook(int keycode, t_vars *vars)
{
	keycode = 5;//togli, serve solo per poter compilare
    vars += 1;//togli, serve solo per poter compilare
    printf("Hello from key_hook!\n");
    return (0);
}
*/

int	close(int keycode, t_vars *vars)
{
    keycode = 5;//togli, serve solo per poter compilare
    vars += 1;//togli, serve solo per poter compilare
	mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_next_frame(void *YourStruct);

int main(void)
{
    t_data  img;
    t_vars  vars;

	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Dolphin game");
    img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    //mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop_hook(vars.mlx, render_next_frame, YourStruct);
    mlx_loop(vars.mlx);
}
