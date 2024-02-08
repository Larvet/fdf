/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:59:13 by locharve          #+#    #+#             */
/*   Updated: 2024/02/07 16:24:57 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1500
# endif

# define HEXA_BASE "0123456789ABCDEF"
# define DECI_BASE "0123456789"

/////////////////////////////////////////////////////////////////// STRUCTURES

typedef struct s_line
{
	char			**split;
	struct s_line	*nxt;
}	t_line;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				c;
	struct s_point	*nxt_x;
	struct s_point	*nxt_y;
}	t_point;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_data;

/////////////////////////////////////////////////////////////////// PARSING

/***/// make_map.c
// static t_line	*read_file(int fd);
// static t_line	*open_file(char *path);
// static int	split_size(char **split);
// static int	equal_lines(t_line *line);
t_point	*make_map(char *path);

/***/// parse_lines.c
// static t_point	*init_point(char **split);
// static t_point	*line_to_chain(t_line *line);
t_point	*parse_lines(t_line *line);

/***/// get_next_line.c
// static char	*ft_strjoin(char *s1, char *s2);
// static char	*ft_read_file(char *line, int fd);
// static char	*ft_fill_line(char *new_l, int fd);
// static char	*ft_strcut(char *src, int c);
char	*get_next_line(int fd);

/***/// get_next_line_utils.c
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *src);
char	*ft_strcat_dst(char *dst, char *s1, char *s2);

/***/// file_check.c
int	ft_isdigit(char c);
// static int	check_path_end(char *big, char *little);
int	is_valid_file(char *str);

/***/// param_check.c
int	z_check(char *str);
int	is_in_base(char *base, char c);
int	c_check(char *str);
void	print_error(char *str);
void	invalid_procedure(t_line *line, char *str, int fd);

/***/// line_lst_utils.c
t_line	*line_new(char **split);
void	line_addback(t_line **lst, t_line *new);
int		line_size(t_line *lst);
void	line_clear(t_line *lst);

/***/// point_lst_utils.c
void	point_addback(t_point **lst, t_point *new);
void	point_clear(t_point *lst);
void	point_meshclear(t_point *lst);
void	point_meshadd(t_point **up, t_point *down);
void	put_x_and_y(t_point **mesh);

/***/// ft_atoll_base.c
int	ft_strlen(char *str);
// static int	before_number(char *str, int *i);
// static int	check_base(char *str);
// static int	index_base(char *base, char c);
long long	ft_atoll_base(char *str, char *base);

/***/// ft_split.c
// static int	count_words(char const *str, char c);
// static char	*str_piece_cpy(const char *s, int start, int end);
// static char	*from_str_to_strs(const char *s, int *i, char c);
void	free_all(char **split);
char	**ft_split(char const *s, char c);

/***/// ft_calloc.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/////////////////////////////////////////////////////////////////// DRAW

/***/// display_all.c
// static void	init_img(t_var var, t_data *img);
// static int	handle_keypress(t_var *var, int keysym);
void	display_all(t_point *map, t_var var);

/***/// draw_map.c
void	draw_map(t_data *img, t_point *map);

/***/// bresenham.c
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
// static void	dx_equals_zero(t_data *img, t_point a, t_point b);
void	bresenham(t_data *img, t_point a, t_point b);

/***///dx_positive.c
// static void	first_octant(t_data *img, t_point a, t_point b, int dx);
// static void	second_octant(t_data *img, t_point a, t_point b, int dx);
// static void	eighth_octant(t_data *img, t_point a, t_point b, int dx);
// static void	seventh_octant(t_data *img, t_point a, t_point b, int dx);
void	dx_positive(t_data *img, t_point a, t_point b, int dx);

/***/// dx_negative.c
// static void	fourth_octant(t_data *img, t_point a, t_point b, int dx);
// static void	third_octant(t_data *img, t_point a, t_point b, int dx);
// static void	fifth_octant(t_data *img, t_point a, t_point b, int dx);
// staticc void	sixth_octant(t_data *img, t_point a, t_point b, int dx);
void	dx_negative(t_data *img, t_point a, t_point b, int dx);

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

#endif
