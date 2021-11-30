/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:29:26 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/27 15:26:45 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	key_hook(int keycode, t_vars *vars)
{
	keycode = 5;//togli, serve solo per poter compilare
    vars += 1;//togli, serve solo per poter compilare
    printf("Movement count: n\n");
    return (0);
}
*/

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        vars->win = NULL;
    }
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
    // t_data  dog;
    //char    *dog_path;
    //int     dog_width;
    // int     dog_height;
    t_vars  vars;
    

	vars.mlx = mlx_init();
    if (vars.mlx == NULL)
		return (MLX_ERROR);
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Puppy game");
    if (vars.win == NULL)
	{
		free(vars.win);
		return (MLX_ERROR);
	}
    img.img = mlx_new_image(vars.mlx, 200, 300);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    my_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
    //dog_path = "./dog.xpm";
    //dog.img = mlx_xpm_file_to_image(vars.mlx, dog_path, &dog_width, &dog_height);
    //dog.addr = mlx_get_data_addr(dog.img, &dog.bits_per_pixel, &dog.line_length, &dog.endian);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
    //mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    //mlx_loop_hook(vars.mlx, render_next_frame, YourStruct);
    mlx_loop(vars.mlx);
	//mlx_destroy_display(vars.mlx);
	//free(vars.mlx);
}
