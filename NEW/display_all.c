/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:44:57 by locharve          #+#    #+#             */
/*   Updated: 2024/02/08 17:44:23 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_img(t_var var, t_data *img)
{
	img->img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
	return ;
}

static int	handle_keypress(t_var *var, int keysym)
{
	printf("%d\n", keysym); /////////////////
	if (keysym == -16777984)
	{
		printf("gros\n"); //////////////////
		mlx_destroy_window(var->mlx, var->win);
		mlx_loop_end(var->mlx);
		var->win = NULL;
	}
	return (0);
}

void	mod_map(t_point **map)
{
	t_point	*head_x;
	t_point	*head_y;

	head_y = *map;
	while (*map)
	{
		head_x = *map;
		while (*map)
		{
			(*map)->x = (*map)->x * 100;
			(*map)->x += HEIGHT / 2;
			(*map)->y *= 100;
			(*map)->y += WIDTH / 2;
			(*map)->z *= 20;
			//(*map)->z += 100;
			*map = (*map)->nxt_x;
		}
		*map = head_x;
		*map = (*map)->nxt_y;
	}
	*map = head_y;
	return ;
}

void	display_all(t_point *map, t_var var)
{
	//t_point	*mod_map;
	t_data	img;

	init_img(var, &img);
	mod_map(&map);
	if (img.img)
	{
		var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "fdf");
		if (var.win)
		{
			//mod_map = (t_point *)lst_dup(map, sizeof(map));
			//if (mod_map)
			rotate_x(&map, 1);
			rotate_y(&map, 1);
			//rotate_z(&map, 1);
			//mod_map(&map);
			draw_map(&img, map);
			mlx_put_image_to_window(var.mlx, var.win, img.img, 0, 0);

			mlx_loop_hook(var.win, &handle_keypress, &var);
			
			
			mlx_loop(var.mlx);

			mlx_destroy_image(var.mlx, img.img);
			//mlx_destroy_window(var.mlx, var.win); ////////
			//if (mod_map)
			//	free(mod_map);
		}
	}
	return ;
}
