/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:19:40 by locharve          #+#    #+#             */
/*   Updated: 2024/02/08 17:10:26 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
	return ;
}

static void	dx_equals_zero(t_data *img, t_point a, t_point b)
{
	if (b.y - a.y > 0)
	{
		while (a.y < b.y)
		{
			my_mlx_pixel_put(img, a.x, a.y, a.c);
			a.y += 1;
		}
	}
	else
	{
		while (a.y > b.y)
		{
			my_mlx_pixel_put(img, a.x, a.y, a.c);
			a.y -= 1;
		}
	}
	return ;
}

void	bresenham(t_data *img, t_point a, t_point b)
{
	int	dx;

	dx = b.x - a.x;
	if (dx > 0)
		dx_positive(img, a, b, dx);
	else if (dx < 0)
		dx_negative(img, a, b, dx);
	else
		dx_equals_zero(img, a, b);
	return ;
}
