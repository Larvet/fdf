/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:49:32 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 17:10:48 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		make_map(&map, argv[1]);
		if (map.tab)
		{
			printf("oklezgo\n");
			// fonction(map);
			free(map.tab);
		}
	}
	return (0);
}
