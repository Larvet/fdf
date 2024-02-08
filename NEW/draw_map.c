/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:19:54 by locharve          #+#    #+#             */
/*   Updated: 2024/02/08 17:09:29 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *img, t_point *map)
{
	t_point	*head_x;
	t_point	*head_y;

	head_y = map;
	while (map)
	{
		head_x = map;
		while (map)
		{
			if (map->nxt_x)
				bresenham(img, *map, *(map->nxt_x));
			if (map->nxt_y)
				bresenham(img, *map, *(map->nxt_y));
			map = map->nxt_x;
		}
		map = head_x;
		map = map->nxt_y;
	}
	map = head_y;
	return ;
}
