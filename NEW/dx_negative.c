/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dx_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:35:47 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fourth_octant(t_data *img, t_point a, t_point b, int dx)
{
	int	dy;
	int	err;

	dy = (b.y - a.y) * 2;
	err = dx;
	dx *= 2;
	while (a.x > b.x)
	{
		my_mlx_pixel_put(img, a.x, a.y, a.c);
		err += dy;
		if (err >= 0)
		{
			a.y += 1;
			err += dx;
		}
		a.x -= 1;
	}
	return ;
}

static void	third_octant(t_data *img, t_point a, t_point b, int dx)
{
	int	dy;
	int	err;

	err = b.y - a.y;
	dy = err * 2;
	dx *= 2;
	while (a.y < b.y)
	{
		my_mlx_pixel_put(img, a.x, a.y, a.c);
		err += dx;
		if (err <= 0)
		{
			a.x -= 1;
			err += dy;
		}
		a.y += 1;
	}
	return ;
}

static void	fifth_octant(t_data *img, t_point a, t_point b, int dx)
{
	int	dy;
	int	err;

	dy = (b.y - a.y) * 2;
	err = dx;
	dx *= 2;
	while (a.x > b.x)
	{
		my_mlx_pixel_put(img, a.x, a.y, a.c);
		err -= dy;
		if (err >= 0)
		{
			a.y -= 1;
			err += dx;
		}
		a.x -= 1;
	}
	return ;
}

static void	sixth_octant(t_data *img, t_point a, t_point b, int dx)
{
	int	dy;
	int	err;

	err = (b.y - a.y);
	dy = err * 2;
	dx *= 2;
	while (a.y > b.y)
	{
		my_mlx_pixel_put(img, a.x, a.y, a.c);
		err -= dx;
		if (err >= 0)
		{
			a.x -= 1;
			err += dy;
		}
		a.y -= 1;
	}
	return ;
}

void	dx_negative(t_data *img, t_point a, t_point b, int dx)
{
	int	dy;

	dy = b.y - a.y;
	if (dy > 0)
	{
		if (-dx >= dy)
			fourth_octant(img, a, b, dx);
		else
			third_octant(img, a, b, dx);
	}
	else if (dy < 0)
	{
		if (dx <= dy)
			fifth_octant(img, a, b, dx);
		else
			sixth_octant(img, a, b, dx);
	}
	else
	{
		while (a.x > b.x)
		{
			my_mlx_pixel_put(img, a.x, a.y, a.c);
			a.x -= 1;
		}
	}
}
