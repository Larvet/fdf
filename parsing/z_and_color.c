/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_and_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:54:37 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 14:30:28 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	put_z(t_point *point, char *str)
{
	long long	tmp;

	tmp = ft_atoll(str);
	if (is_valid_nbr(tmp))
	{
		point->z = (int)tmp;
		return (1);
	}
	else
	{
		print_error("Invalid number\n");
		return (0);
	}
}

static int	put_color(t_point *point, char *str)
{
	int	tmp;

	tmp = is_valid_color(str);
	if (tmp < 0)
	{
		print_error("Invalid color\n");
		return (0);
	}
	else
	{
		point->color = tmp;
		return (1);
	}
}

int	z_and_color(t_point *point, char **split_point)
{
	if (split_point[0])
	{
		if (!put_z(point, split_point[0]))
			return (0);
		if (split_point[1])
		{
			if (!put_color(point, split_point[1]))
				return (0);
			if (split_point[2])
			{
				print_error("Unexpected parameter\n");
				return (0);
			}
		}
		return (1);
	}
	return (0);
}
