/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:26:18 by locharve          #+#    #+#             */
/*   Updated: 2024/01/31 16:45:43 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h> // TMP /////////////////

# define HEX_BASE "0123456789ABCDEF"

////////////////////////////////////////////////////////////// STRUCTURES

typedef struct s_line
{
	char			*line;
	int				count;
	struct s_line	*nxt;
}	t_line;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	*tab;
	int		width;
	int		height;
}	t_map;

////////////////////////////////////////////////////////////// PARSING

/**/// parsing.c // A MODIFIER
// static int	equal_lines(t_line *line_tab);
// static int	separate_points(t_line *l_tab, t_point *p_tab, int *i);
// static t_point	*convert_lines(t_line *l_tab);
// static t_point	*parsing(t_line *line_tab, char *path);
int			make_map(t_map *map, char *path);

/**/// init_point_tab.c
// static int	put_color(char *str);
// static int	check_z(char *str, long long *tmp);
int			init_point_tab(t_point *p_tab, char **split, int *i, int count);

/**/// parsing_utils.c
void		invalid_procedure(t_line *line_tab, char *str, int fd);
void		free_map(t_point **map, int size);
int			split_size(char **split);
long long	ft_atoll(char *str);
t_line		*read_file(int fd);

/**/// ft_calloc.c
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

/**/// ft_strdup.c
// static char	*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *s);

/**/// free_all_map.c
void		free_all_map(t_point **map);

/**/// ft_atoi_base.c
int			ft_strlen(char *str);
// static int	before_number(char *str, int *i);
// static int	check_base(char *str);
// static int	index_base(char *base, char c);
long long	ft_atoll_base(char *str, char *base);

/**/// is_valid.c
int			is_valid_nbr(long long nbr);
int			is_in_base(char *base, char c);
int			is_valid_str(char *str);
int			is_valid_color(char *str);

/**/// file_check.c
// static int	check_path(char *big, char *little);
int			is_valid_file(char *str);

/**/// check_fonctions.c
int			ft_isdigit(char c);
int			ft_isspace(char c);
int			ft_issign(char c);
int			ft_isascii(int c);

/**/// line_lst_utils.c
t_line		*line_lstnew(char *str);
void		line_lstadd_back(t_line **lst, t_line *new);
int			line_lstsize(t_line *lst);
void		line_lstclear(t_line *lst);

/**/// ft_split.c
int			count_words(char const *str, char c);
// static char	*str_piece_cpy(const char *s, int start, int end);
// static char	*from_str_to_strs(const char *s, int *i, char c);
void		free_all(char **split, int nbr_str);
char		**ft_split(char const *s, char c);

/**/// print_error.c
void		print_error(char *str);

////////////////////////////////////////////////////////////// ALGORITHM

////////////////////////////////////////////////////////////// OTHERS

#endif
