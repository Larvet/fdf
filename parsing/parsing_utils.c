/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:38:29 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 16:02:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	invalid_procedure(t_line *line_tab, char *str, int fd)
{
	line_lstclear(line_tab);
	line_tab = NULL;
	free(str);
	close(fd);
	str = get_next_line(fd);
	free(str);
	return ;
}

void	free_map(t_point **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*map + i))
			free((*map + i));
		i++;
	}
	return ;
}

int	split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

long long	ft_atoll(char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = ft_issign(str[i]);
	if (sign)
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = str[i] - 48 + result * 10;
		i++;
	}
	if (sign)
		result *= sign;
	return (result);
}

t_line	*read_file(int fd)
{
	t_line	*tmp;
	t_line	*line_tab;
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
