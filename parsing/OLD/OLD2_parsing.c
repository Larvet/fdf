/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:06:54 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 14:33:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_points(t_point *point_tab, char **split_line, int y)
{
	char		**split_point;
	int			i;

	i = 0;
	while (split_line[i])
	{
		split_point = ft_split(split_line[i], ',');
		if (!split_point)
			return (0);
		point_tab[i].x = i;
		point_tab[i].y = y;
		if (!z_and_color(&point_tab[i], split_point))
		{
			free_all(split_line, split_size(split_line));
			free(split_point);
			return (0);
		}
		i++;
	}
	return (1);
}

static t_point	*split_line(char *line, int y)
{
	t_point	*point_tab;
	char	**split_line;
	int		size;
	int		i;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (NULL);
	size = split_size(split_line);
	point_tab = (t_point *)ft_calloc(size + 1, sizeof(t_point));
	if (point_tab)
	{
		i = 0;
		while (split_line[i])
		{
			if (!init_points(point_tab, split_line, y))
			{
				free_all(split_line, split_size(split_line));
				free_map(&point_tab, i); /////////////////
				return (NULL);
			}
			free(split_line[i]);
			i++;
		}
		free(split_line);
	}
	return (point_tab);
}

static void	init_map(t_point **map, t_line *line_tab)
{
	t_line	*head;
	int		i;

	head = line_tab;
	i = 0;
	while (line_tab)
	{
		map[i] = split_line(line_tab->line, i);
		if (!map[i])
		{
			free_all_map(map);
			return ;
		}
		line_tab = line_tab->nxt;
		i++;
	}
	line_tab = head;
	return ;
}

t_point	**parsing(char *path)
{
	t_line	*line_tab;
	t_point	**map;
	int		size;

	line_tab = read_file(path);
	if (line_tab)
	{
		size = line_lstsize(line_tab);
		map = (t_point **)ft_calloc(size + 1, sizeof(t_point *)); ///
		if (map)
			init_map(map, line_tab);
		//*//
		line_lstclear(line_tab);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_point	**map;

	if (argc == 2 && is_valid_file(argv[1]))
	{
		map = parsing(argv[1]);
		if (map)
		{
			write(1, "OK\n", 3);
			free_all_map(map);
		}
	}
	return (0);
}
