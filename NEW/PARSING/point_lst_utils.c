/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:51:08 by locharve          #+#    #+#             */
/*   Updated: 2024/02/06 19:24:11 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_addback(t_point **lst, t_point *new)
{
	if (!(*lst))
		*lst = new;
	else
		point_addback(&(*lst)->nxt_x, new);
	return ;
}

void	point_clear(t_point *lst)
{
	if (lst->nxt_x)
		point_clear(lst->nxt_x);
	if (lst)
		free(lst);
	return ;
}

void	point_meshclear(t_point *lst)
{
	if (lst->nxt_y)
		point_meshclear(lst->nxt_y);
	if (lst)
		point_clear(lst);
	return ;
}

void	point_meshadd(t_point **up, t_point *down)
{
	t_point	*head_up;
	t_point	*head_down;

	head_up = *up;
	head_down = down;
	if (!(*up))
	{
		*up = down;
		return ;
	}
	while ((*up)->nxt_y)
		*up = (*up)->nxt_y;
	while (*up)
	{
		(*up)->nxt_y = down;
		*up = (*up)->nxt_x;
		down = down->nxt_x;
	}
	*up = head_up;
	down = head_down;
	return ;
}

void	put_x_and_y(t_point **mesh)
{
	t_point	*head_x;
	t_point	*head_y;
	int	x;
	int	y;

	head_y = *mesh;
	y = 0;
	while (*mesh)
	{
		head_x = *mesh;
		x = 0;
		while (*mesh)
		{
			(*mesh)->x = x;
			(*mesh)->y = y;
			*mesh = (*mesh)->nxt_x;
			x++;
		}
		*mesh = head_x;
		*mesh = (*mesh)->nxt_y;
		y++;
	}
	*mesh = head_y;
	return ;
}
