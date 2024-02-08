/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:57:30 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 15:29:45 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*init_point(char **split)
{
	t_point		*result;

	result = ft_calloc(1, sizeof(t_point));
	if (!result)
		return (NULL);
	if (z_check(split[0]))
		result->z = ft_atoll_base(split[0], DECI_BASE);
	if (split[1] && c_check(split[1]))
	{
		result->c = ft_atoll_base(&split[1][2], HEXA_BASE);
		if (split[2])
		{
			print_error("Unexpected parameter\n");
			free(result);
		}
	}
	else
		result->c = 0xFFFFFF;
	return (result);
}

static t_point	*line_to_chain(t_line *line)
{
	t_point	*tmp;
	t_point	*result;
	char	**split;
	int		i;

	result = NULL;
	i = 0;
	while (line->split[i] && ft_isdigit(line->split[i][0]))
	{
		split = ft_split(line->split[i], ',');
		if (!split)
		{
			point_clear(result);
			return (NULL);
		}
		tmp = init_point(split);
		if (!tmp)
		{
			point_clear(result);
			return (NULL);
		}
		point_addback(&result, tmp);
		free_all(split);
		i++;
	}
	return (result);
}

t_point	*parse_lines(t_line *line)
{
	t_point	*tmp;
	t_point	*result;
	t_line	*head;

	result = NULL;
	head = line;
	while (line)
	{
		tmp = line_to_chain(line);
		if (!tmp)
		{
			point_meshclear(result);
			return (NULL);
		}
		point_meshadd(&result, tmp);
		line = line->nxt;
	}
	line = head;
	put_x_and_y(&result);
	return (result);
}
