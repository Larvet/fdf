/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:02:10 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 17:09:22 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*lst_dup(void *lst, size_t size)
{
	unsigned char	*result;
	unsigned char	*ptr;
	size_t			i;

	result = malloc(size * sizeof(unsigned char));
	if (!result)
		return (NULL);
	ptr = lst;
	i = 0;
	while (i < size)
	{
		result[i] = ptr[i];
		i++;
	}
	return ((void *)result);
}
