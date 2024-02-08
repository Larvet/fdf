/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:17:15 by locharve          #+#    #+#             */
/*   Updated: 2024/02/08 17:25:41 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// double cos(double)
/*
static double	calculate_new_pos(double a, double b, double c, double d)
{
	double	result;

	result = a * b + c * d;
	printf("new pos %f\n", result);
	return (result);
}
*/
void	rotate_x(t_point **map, double angle)
{
	t_point	*head_y;
	t_point	*head_x;

	head_y = *map;
	while (*map)
	{
		head_x = *map;
		while (*map)
		{
			//(*map)->y_d = calculate_new_pos((*map)->y, cos(angle), -((*map)->z), sin(angle));
			//(*map)->z_d = calculate_new_pos((*map)->y, sin(angle), (*map)->z, cos(angle));
			(*map)->x *= 1;
			(*map)->y = floor((*map)->y * cos(angle) - (*map)->z * sin(angle) * 1);
			(*map)->z = floor((*map)->y * sin(angle) + (*map)->z * cos(angle) * 1);
			*map = (*map)->nxt_x;
		}
		*map = head_x;
		*map = (*map)->nxt_y;
	}
	*map = head_y;
	return ;
}

void	rotate_y(t_point **map, double angle)
{
	t_point	*head_y;
	t_point	*head_x;

	head_y = *map;
	while (*map)
	{
		head_x = *map;
		while (*map)
		{
			(*map)->x = floor((*map)->x * cos(angle) + (*map)->z * sin(angle));
			(*map)->z = floor(-((*map)->x) * sin(angle) + (*map)->z * cos(angle));
			*map = (*map)->nxt_x;
		}
		*map = head_x;
		*map = (*map)->nxt_y;
	}
	*map = head_y;
	return ;
}

void	rotate_z(t_point **map, double angle)
{
	t_point	*head_y;
	t_point	*head_x;

	head_y = *map;
	while (*map)
	{
		head_x = *map;
		while (*map)
		{
			(*map)->x = floor((*map)->x * cos(angle) - (*map)->y * sin(angle));
			(*map)->y = floor((*map)->y * cos(angle) + (*map)->x * sin(angle));
			*map = (*map)->nxt_x;
		}
		*map = head_x;
		*map = (*map)->nxt_y;
	}
	*map = head_y;
	return ;
}
