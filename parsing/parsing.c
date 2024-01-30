/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:20 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 17:09:04 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

// verifs : map valide ? ouvrable ? 

static t_line	*read_file(int fd)
{
	t_line	*line_tab;
	t_line	*tmp;
	char	*str;

	line_tab = NULL;
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

static int	init_point_tab(t_point *p_tab, char **split, int *i)
{
	long long	tmp;
	int			j;

	j = 0;
	while (split[j])
	{
		printf("|%s|\n", split[j]); /////////////////
		if (!is_valid_str(split[j]))
		{
			print_error("Invalid format\n");
			return (0);
		}
		tmp = ft_atoll(split[j]);
		if (!is_valid_nbr(tmp))
		{
			print_error("Invalid number\n");
			return (0);
		}
		p_tab[*i].x = j;
		p_tab[*i].z = (int)tmp;
		tmp = is_valid_color(ft_strchr(split[j], ','));
		//printf("color = %d\n", (int)tmp); //////////////////
		if (tmp > -2)
		{
			if (tmp == -1)
			{
				print_error("Invalid color\n");
				return (0);
			}
			p_tab[*i].color = (int)tmp;
		}
		else
			p_tab[*i].color = -1;
		*i += 1;
		j++;
	}
	return (1);
}

static t_point	*convert_lines(t_line *l_tab)
{
	t_line	*head;
	t_point	*p_tab;
	char	**split;
	int		i;

	head = l_tab;
	p_tab = ft_calloc((line_lstsize(l_tab) * l_tab->count) + 1, sizeof(*p_tab));
	//printf("size = %d\n", (line_lstsize(l_tab) * l_tab->count) + 1); ////////
	if (!p_tab)
		return (NULL);
	i = 0;
	while (l_tab)
	{
		split = ft_split(l_tab->line, ' ');
		if (!split)
		{
			free(p_tab);
			return (NULL);
		}
		if (!init_point_tab(p_tab, split, &i))
		{
			free_all(split, l_tab->count);
			free(p_tab);
			l_tab = head;
			return (NULL);
		}
		p_tab[i].y = i / l_tab->count; ////////////////////
		free_all(split, l_tab->count);
		l_tab = l_tab->nxt;
	}
	p_tab[i].color = -2; //////////////
	l_tab = head;
	return (p_tab);
}

t_point	*parsing(char *path)
{
	t_line	*line_tab;
	t_point	*point_tab;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Cannot open file\n");
		return (NULL);
	}
	line_tab = read_file(fd);
	if (!equal_lines(line_tab))
	{
		print_error("Invalid map\n");
		line_lstclear(line_tab);
		return (NULL);
	}
	point_tab = convert_lines(line_tab);
	line_lstclear(line_tab);
	return (point_tab);
}

int	main(int argc, char **argv)
{
	t_point	*map;
	int		i;

	if (argc == 2)
	{
		// check le path *.fdf
		map = parsing(argv[1]);
		if (map)
		{
			printf("ok gro.\n");
			i = 0;
			while (map[i].color >= -1)
			{
				printf("x = %d\ty = %d\tz = %d\tcolor = %d\n", map[i].x, map[i].y, map[i].z, map[i].color);
				i++;
			}
			free(map);
		}
	}
	return (0);
}
