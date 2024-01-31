/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:01:47 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 16:47:15 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_nbr(long long nbr)
{
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (1);
	else
		return (0);
}

int	is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (c != base[i] && c != base[i] + 32)
		i++;
	if (!base[i])
		return (0);
	else
		return (1);
}

int	is_valid_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] && ft_issign(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	else if (str[i] && str[i] != ',')
		return (0);
	i++;
	if (str[i] != '0')
		return (0);
	i++;
	if (str[i] != 'x')
		return (0);
	i++;
	while (str[i] && is_in_base(HEX_BASE, str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	is_valid_color(char *str)
{
	long long	color;

	if (!str)
		return (-2);
	if (str[0] && str[0] == '0' && str[1] && str[1] == 'x')
	{
		if (str[2])
		{
			color = ft_atoll_base(&str[2], HEX_BASE);
			if (color >= 0 && color <= 16777215)
				return ((int)color);
		}
	}
	return (-1);
}
