/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:20 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 16:48:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int	equal_lines(t_line *line_tab)
{
	t_line	*head;

	head = line_tab;
	while (line_tab && line_tab->nxt && line_tab->count == line_tab->nxt->count)
		line_tab = line_tab->nxt;
	if (!line_tab->nxt)
	{
		line_tab = head;
		return (1);
	}
	else
	{
		line_tab = head;
		return (0);
	}
}

static int	separate_points(t_line *l_tab, t_point *p_tab, int *i)
{
	char	**split;

	split = ft_split(l_tab->line, ' ');
	if (!split)
		return (0);
	if (!init_point_tab(p_tab, split, i, l_tab->count))
	{
		free_all(split, l_tab->count);
		return (0);
	}
	free_all(split, l_tab->count);
	return (1);
}

static t_point	*convert_lines(t_line *l_tab)
{
	t_line	*head;
	t_point	*p_tab;
	int		i;

	head = l_tab;
	p_tab = ft_calloc((line_lstsize(l_tab) * l_tab->count) + 1, sizeof(*p_tab));
	if (!p_tab)
		return (NULL);
	i = 0;
	while (l_tab)
	{
		if (!separate_points(l_tab, p_tab, &i))
		{
			free(p_tab);
			l_tab = head;
			return (NULL);
		}
		l_tab = l_tab->nxt;
	}
	p_tab[i].color = -2;
	l_tab = head;
	return (p_tab);
}

static t_point	*parsing(t_line **line_tab, char *path)
{
	t_point	*point_tab;
	int		fd;

	if (!is_valid_file(path))
	{
		print_error("Invalid file\n");
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Cannot open file\n");
		return (NULL);
	}
	*line_tab = read_file(fd);
	if (!equal_lines(*line_tab))
	{
		print_error("Invalid map\n");
		return (NULL);
	}
	point_tab = convert_lines(*line_tab);
	return (point_tab);
}

int	make_map(t_map *map, char *path)
{
	t_line	*line_tab;

	line_tab = NULL;
	map->tab = parsing(&line_tab, path);
	if (!map->tab)
	{
		if (line_tab)
			line_lstclear(line_tab);
		return (0);
	}
	map->width = line_tab->count;
	map->height = line_lstsize(line_tab);
	line_lstclear(line_tab);
	return (1);
}
