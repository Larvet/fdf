/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:46:41 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 11:58:59 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_path_end(char *big, char *little)
{
	int	i;
	int	j;
	
	if (!big || !little)
		return (0);
	i = 0;
	while (big[i])
		i++;
	j = 0;
	while (little[j])
		j++;
	while (i >= 0 && j >= 0 && big[i] == little[j])
	{
		i--;
		j--;
	}
	if (j < 0)
		return (1);
	else
		return (0);
}

int	is_valid_file(char *str)
{
	if (!check_path_end(str, ".fdf\0"))
		return (0);
	else
		return (1);
}
