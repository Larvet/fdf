/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:42:56 by locharve          #+#    #+#             */
/*   Updated: 2024/02/06 19:33:37 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_point	*map;

	if (argc == 2)
	{
		map = make_map(argv[1]);
		if (map)
		{
			t_point	*head_y = map;
			while (map)
			{
				t_point	*head_x = map;
				while (map)
				{
					printf("%d\t", map->z);
					map = map->nxt_x;
				}
				printf("\n");
				map = head_x;
				map = map->nxt_y;
			}
			map = head_y;
			point_meshclear(map);
		}
	}
	return (0);
}
