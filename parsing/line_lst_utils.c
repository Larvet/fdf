/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:46:07 by locharve          #+#    #+#             */
/*   Updated: 2024/01/30 15:45:21 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*line_lstnew(char *str)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->line = ft_strdup(str);
	new->count = count_words((char const *)new->line, ' ');
	new->nxt = NULL;
	return (new);
}

void	line_lstadd_back(t_line **lst, t_line *new)
{
	if (!(*lst))
		*lst = new;
	else
		line_lstadd_back(&(*lst)->nxt, new);
	return ;
}

int	line_lstsize(t_line *lst)
{
	if (lst)
		return (1 + line_lstsize(lst->nxt));
	else
		return (0);
}

void	line_lstclear(t_line *lst)
{
	if (lst->nxt)
		line_lstclear(lst->nxt);
	if (lst->line)
		free(lst->line);
	if (lst)
		free(lst);
	return ;
}
