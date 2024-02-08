/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:32:22 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 15:44:49 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point	*map;
	t_var	var;

	if (argc == 2)
	{
		map = make_map(argv[1]);
		if (map)
		{
			var.mlx = mlx_init();
			if (var.mlx)
			{
				display_all(map, var);
				mlx_destroy_display(var.mlx);
				free(var.mlx);
			}
			point_meshclear(map);
		}
	}
	return (0);
}
