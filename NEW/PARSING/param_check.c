/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:03:13 by locharve          #+#    #+#             */
/*   Updated: 2024/02/06 19:06:18 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	z_check(char *str)
{
	long long	tmp;
	int			i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	tmp = ft_atoll_base(DECI_BASE, str);
	if (tmp >= -2147483648 && tmp <= 2147483647)
		return (1);
	else
	{
		print_error("Invalid number\n");
		return (0);
	}
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

int	c_check(char *str)
{
	int			i;

	if (str[0] && str[0] == '0' && str[1] && str[1] == 'x')
	{
		i = 2;
		while (str[i] && is_in_base(HEXA_BASE, str[i]))
			i++;
		if (!(str[i] && str[i] != '\n' && i > 9))
			return (1);
	}
	print_error("Invalid color\n");
	return (0);
}

void	print_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
		write(2, str, ft_strlen(str));
	return ;
}

void	invalid_procedure(t_line *line, char *str, int fd)
{	
	line_clear(line);
	line = NULL;
	free(str);
	close(fd);
	str = get_next_line(fd);
	free(str);
	return ;
}
