/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:01:47 by locharve          #+#    #+#             */
/*   Updated: 2024/01/29 12:11:49 by locharve         ###   ########.fr       */
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

int	is_valid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_issign(str[i]) && ((i > 0 && !ft_isspace(str[i - 1]))
				|| !ft_isdigit(str[i + 1])))
			return (0);
		if (!ft_issign(str[i]) && !ft_isspace(str[i]) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_color(int nbr)
{
	if (nbr >= 0 && nbr <= 16777215)
		return (1);
	else
		return (0);
}
