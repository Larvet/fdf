/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:46:07 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 15:23:10 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*line_new(char **split)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->split = split;
	new->nxt = NULL;
	return (new);
}

void	line_addback(t_line **lst, t_line *new)
{
	if (!(*lst))
		*lst = new;
	else
		line_addback(&(*lst)->nxt, new);
	return ;
}

int	line_size(t_line *lst)
{
	if (lst)
		return (1 + line_size(lst->nxt));
	else
		return (0);
}

void	line_clear(t_line *lst)
{
	if (lst && lst->nxt)
		line_clear(lst->nxt);
	if (lst && lst->split)
		free_all(lst->split);
	if (lst)
		free(lst);
	return ;
}
