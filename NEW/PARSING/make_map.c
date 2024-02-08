/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:58:03 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 15:29:51 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	*read_file(int fd)
{
	t_line	*tmp;
	t_line	*result;
	char	**split;
	char	*str;

	result = NULL;
	str = get_next_line(fd);
	while (str)
	{
		split = ft_split(str, ' ');
		tmp = line_new(split);
		if (!tmp || !split || !ft_isdigit(split[0][0]))
		{
			invalid_procedure(result, str, fd);
			if (tmp)
				free(tmp);
			if (split)
				free_all(split);
			return (NULL);
		}
		line_addback(&result, tmp);
		free(str);
		str = get_next_line(fd);
	}
	return (result);
}

static t_line	*open_file(char *path)
{
	t_line	*result;
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
	result = read_file(fd);
	if (result)
		close(fd);
	return (result);
}

static int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	equal_lines(t_line *line)
{
	t_line	*head;
	int		count;

	head = line;
	count = split_size(line->split);
	line = line->nxt;
	while (line && count == split_size(line->split))
		line = line->nxt;
	if (!line)
		count = 1;
	else
		count = 0;
	line = head;
	return (count);
}

t_point	*make_map(char *path)
{
	t_point	*result;
	t_line	*line;

	result = NULL;
	line = open_file(path);
	if (line)
	{
		if (!equal_lines(line))
			print_error("Invalid map\n");
		else
			result = parse_lines(line);
		line_clear(line);
	}
	return (result);
}
