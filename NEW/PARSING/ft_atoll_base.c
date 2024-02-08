/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:33:48 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 15:31:11 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	before_number(char *str, int *i)
{
	int	signe;

	signe = 1;
	while ((str[*i] >= 7 && str[*i] <= 13) || str[*i] == 32)
		*i = *i + 1;
	while (str[*i] == 43 || str[*i] == 45)
	{
		if (str[*i] == 45)
			signe *= -1;
		*i = *i + 1;
	}
	return (signe);
}

static int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == 43 || str[i] == 45)
			return (0);
		j = 0;
		while (str[j] != '\0')
		{
			if (i != j && str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	index_base(char *base, char c)
{
	int	i;

	i = 0;
	while (c != base[i] && c != base[i] + 32)
		i++;
	return (i);
}

long long	ft_atoll_base(char *str, char *base)
{
	int			i;
	int			sign;
	long long	result;
	int			index;
	int			len_base;

	if (check_base(base) == 0)
		return (0);
	i = 0;
	result = 0;
	len_base = ft_strlen(base);
	sign = before_number(str, &i);
	index = index_base(base, str[i]);
	while (index >= 0 && index < len_base)
	{
		result = index + result * len_base;
		i++;
		index = index_base(base, str[i]);
	}
	return (result * sign);
}
