/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:25:25 by locharve          #+#    #+#             */
/*   Updated: 2024/01/25 16:00:24 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

static void	invalid_procedure(t_line *line_tab, char *str, int fd)
{
	line_lstclear(line_tab);
	line_tab = NULL;
	free(str);
	close(fd);
	str = get_next_line(fd);
	free(str);
	return ;
}

static t_line	*read_file(char *path)
{
	t_line	*tmp;
	t_line	*line_tab;
	char	*str;
	int		fd;

	line_tab = NULL;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		tmp = line_lstnew(str);
		if (!tmp)
		{
			invalid_procedure(line_tab, str, fd);
			return (NULL);
		}
		line_lstadd_back(&line_tab, tmp);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (line_tab);
}

static int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static t_point	fill_point(t_point *point, char *str, int x, int y)
{
	char	**split;
	int		tmp;

	split = ft_split(str, ',');
	if (!split)
		return (NULL);
	tmp = ft_atoll(split[0]);	//////////////////////////////////////////
	if (!is_valid_nbr(tmp))		//////////////////////////////////////////
	{
		// free split
		return (NULL);
	}
	point->x = x;
	point->y = y;
	point->z = (int)tmp;
	if (split[1])
	{
		if (is_valid_color)
			point->color = ft_atoi_hexa(split[1]); ///////////////////////
		else
		{
			// free all
			return (NULL);
		}
	}
}

static t_point	*line_to_points(char *line, int y)
{
	t_point	*point_tab;
	char	**split;
	int		size;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	size = split_size(split);
	point_tab = (t_point *)malloc((size + 1) * sizeof(t_point));
	if (!point_tab)
	{
		// free all
		return (NULL);
	}
	i = 0;
	while (split[i])
	{
		fill_point(&point_tab[i], split[i], i, y);
		if (!point_tab[i]) ///////
		{
			// free all 
			return (NULL;
		}
		i++;
	}
	// free all split
	return (point_tab);
}

static t_point	**lines_to_map(t_line *line_tab)
{
	t_point	**map;
	t_line	*head;
	int		size;
	int		i;

	size = line_lstsize(line_tab);
	map = (t_point **)malloc((size + 1) * sizeof(t_point *));
	if (!map)
		return (NULL);
	head = line_tab;
	i = 0;
	while (i < size)
	{
		map[i] = line_to_points(line_tab->line, i);
		if (!map[i])
		{
			// free all
			return (NULL);
		}
		line_tab = line_tab->nxt;
		i++;
	}
	line_tab = head;
	return (map);
}

t_point	*parsing(char *path)
{
	t_line	*line_tab;
	t_point	**map;
	int		i;
	int		size;

	map = NULL;
	line_tab = read_file(path); // verifier le path : *.fdf
	if (line_tab)
	{
		map = lines_to_points(line_tab);
		/*
		point_tab = (t_point **)malloc(size + 1) * sizeof(t_point *);
		if (point_tab)
		{
			i = 0;
			while (i < size)
			{
				point_tab[i] = 
			}
		}
		*/
		line_lstclear(line_tab);
	}
}
