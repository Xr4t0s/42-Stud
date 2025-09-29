/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:54:16 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/10 14:54:16 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <X11/Xlib.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# ifndef ESC_KEY
#  define ESC_KEY 65307
# endif
# ifndef COS_30
#  define COS_30 0.86602540378
# endif
# ifndef SIN_30
#  define SIN_30 0.5
# endif

// STRUCT

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
	int		color;
}	t_line;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_imgdata;

typedef struct s_map
{
	int	x;
	int	y;
	int	index;
	int	*coords;
}	t_map;

typedef struct s_controller
{
	char				*filename;
	void				*mlx_ptr;
	void				*window;
	int					width;
	int					height;
	double				scale;
	double				z_factor;
	int					offset_x;
	int					offset_y;
	t_imgdata			img;
	t_map				map;
	t_mouse				mouse;
	struct s_controller	*next;
}	t_controller;

// INIT
void	init_controller(t_controller *multiplex, char *filename);

// CONFIG
void	configure_all(t_controller *multiplex);
void	configure_hooks(t_controller *multiplex);
void	configure_hooks(t_controller *multiplex);
int	deal_key(int key, t_controller *multiplex);

// FREE
void	free_controller(t_controller *multiplex);

// FDF
void	configure_img(t_controller *multiplex);

// DRAWINGS
void	put_pixel(t_imgdata *img, int x, int y, int color);
void	draw_map(t_controller *multiplex);
void	draw_font(t_controller *multiplex);
void	draw_line(t_imgdata *img, t_line line);
double	calculate_scale(t_controller *data);

// PARSING
void	parse_map(char *filename, t_controller *multiplex);
char	*delete_new_lines(char *xyz);
int		count_lines(const char *buffer);
int		count_word(const char *s, char c);

// GNL
char	*get_next_line(int fd);

// ERR
void	ft_return(char *error, int exit_code, t_controller *s_controller);

#endif