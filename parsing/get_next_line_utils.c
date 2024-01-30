/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:29:58 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 14:11:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (&str[i + 1]);
	}
	return (NULL);
}

char	*ft_strcat_dst(char *dst, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
