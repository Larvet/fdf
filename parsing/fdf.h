/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:18 by locharve          #+#    #+#             */
/*   Updated: 2024/01/29 12:17:17 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789ABCDEF"

////////////////////////////////////////////////////////////// STRUCTURES

typedef struct s_line
{
	char			*line;
	struct s_str	*nxt;
}	t_line;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

////////////////////////////////////////////////////////////// PARSING

/**/// parsing.c
// static int	z_and_color(t_point **point, char *split_point);
// static void	init_points(t_point **point_tab, char *split_line, int y);
// static t_point	*split_line(char *line, int y);
// static void	init_map(t_point ***map, t_line *line_tab);
t_point		**parsing(char *path);

/**/// parsing_utils.c
void		invalid_procedure(t_line *line_tab, char *str, int fd);
void		free_map(t_point **map, int size);
int			split_size(char **split);
long long	ft_atoll(char *str);
t_line		*read_file(char *path);

/**/// ft_atoi_base.c
// static int	ft_strlen(char *str);
// static int	before_number(char *str, int *i);
// static int	check_base(char *str);
// static int	index_base(char *base, char c);
int			ft_atoi_base(char *str, char *base);

/**/// is_valid.c
int			is_valid_nbr(long long nbr);
int			is_valid_str(char *str);
int			is_valid_color(int nbr);

/**/// check_fonctions.c
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_issign(char c);

/**/// line_lst_utils.c
t_line		*line_lstnew(char *str);
void		line_lstadd_back(t_line **lst, t_line *new);
int			line_lstsize(t_line *lst);
void		line_lstclear(t_line *lst);

/**/// ft_split.c
// static int	count_words(char const *str, char c);
// static char	*str_piece_cpy(const char *s, int start, int end);
// static char	*from_str_to_strs(const char *s, int *i, char c);
void		free(all(char **split, int nbr_str);
char		**ft_split(char const *s, char c);

////////////////////////////////////////////////////////////// ALGORITHM



////////////////////////////////////////////////////////////// OTHERS
