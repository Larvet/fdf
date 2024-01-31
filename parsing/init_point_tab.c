/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:48:32 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 14:49:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int	put_color(char *str)
{
	char		*tmp;
	long long	nbr;

	tmp = ft_strchr(str, ',');
	nbr = is_valid_color(tmp);
	if (nbr > -2)
	{
		if (nbr == -1)
		{
			print_error("Invalid color\n");
			return (-2);
		}
		return ((int)nbr);
	}
	else
		return (-1);
}

static int	check_z(char *str, long long *tmp)
{
	if (!is_valid_str(str))
	{
		print_error("Invalid format\n");
		return (0);
	}
	*tmp = ft_atoll(str);
	if (!is_valid_nbr(*tmp))
	{
		print_error("Invalid number\n");
		return (0);
	}
	return (1);
}

int	init_point_tab(t_point *p_tab, char **split, int *i, int count)
{
	long long	tmp;
	int			j;

	j = 0;
	while (split[j])
	{
		if (!check_z(split[j], &tmp))
			return (0);
		else
			p_tab[*i].z = (int)tmp;
		p_tab[*i].x = j;
		p_tab[*i].y = *i / count;
		p_tab[*i].color = put_color(split[j]);
		if (p_tab[*i].color == -2)
			return (0);
		*i += 1;
		j++;
	}
	return (1);
}
