/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:06:54 by locharve          #+#    #+#             */
/*   Updated: 2024/01/29 12:18:13 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	z_and_color(t_point **point, char **split_point)
{
	long long	tmp;

	if (split_point[0])
	{
		tmp = ft_atoll(split_point[0]);
		if (is_valid_nbr(split_point[i])) /////////
			(*point_tab)->z = (int)tmp;
		else
		{
			print_error("Invalid number.\n"); ///////////
			return (0);
		}
	}
	if (split_point[1])
	{
		if (is_valid_color(split_point[1])) ///////////////
			(*point_tab)->color = ft_atoi_base(split_point[1], HEX_BASE);
		else
		{
			print_error("Invalid color.\n");
			return (0);
		}
		if (split_point[2])
		{
			print_error("Unexpected parameter.\n");
			return (0);
		}
	}
	return (1);
}

static void	init_points(t_point **point_tab, char **split_line, int y)
{
	char		**split_point;
	long long	tmp;
	int			i;

	i = 0;
	while (split_line[i])
	{
		split_point = ft_split(split_line, ',');
		if (!split_point)
			return (NULL);
		(*point_tab + i)->x = i;
		(*point_tab + i)->y = y;
		if (!z_and_color(&(*point_tab + i), split_point))
		{
			free(split_point);
			return (NULL);
		}

		// check str avant ?
		tmp = ft_atoll(split[i]); /////////////////////////
		if (is_valid_nbr(tmp) && is_valid_str(split[i])) //////////
			(*point_tab)->z = (int)tmp;
		else
		{
			print_error("Invalid number.\n");

		}
		//
		i++;
	} //////////////////////////////
}

static t_point	*split_line(char *line, int y)
{
	t_point	*point_tab;
	char	**split_line;
	int		size;
	int		i;

	split_line = ft_split(line, ' ');
	if (!split)
		return (NULL);
	size = split_size(split_line);
	point_tab = (t_point *)malloc((size + 1) * sizeof(t_point));
	if (point_tab)
	{ /////////////////////////////////
		i = 0;
		while (split_line[i])
		{
			split_point = ft_split(split_line[i], ',');
			if (!split_point)
			{
				free_all(split_line, size); //////////////
				return (NULL);
			}
			i++;
		}
		init_points(&point_tab, split, y);
	return (point_tab);
}

static void	init_map(t_point ***map, t_line *line_tab)
{
	t_line	*head;

	head = line_tab;
	i = 0;
	while (line_tab)
	{
		(*map)[i] = split_line(line_tab->line, i);
		if (!(*map)[i])
		{
			free_map(*map, size);	//////
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
	//int		i;
	int		size;

	line_tab = read_file(path);
	if (line_tab)
	{
		size = line_lstsize(line_tab);
		map = (t_point **)malloc((size + 1) * sizeof(t_point *)); ///
		if (map)
			init_map(&map, line_tab);
		//*//
		line_lstclear(line_tab);
	}
	return (map);
}
