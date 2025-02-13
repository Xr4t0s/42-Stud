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

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32768
# endif

// MAP
typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	*coords;
} t_map;

void	map_init(t_map **map);
t_map	*map(char *xyz);


// ENV
typedef struct s_window
{
	void	*mlx_ptr;
	void	*window;
	void	*img;
} t_window;


// PARSING
t_map	*parse_map(char *filename);
char	*delete_new_lines(char *xyz);
int		count_lines(const char *buffer);
int		count_word(const char *s, char c);

// GNL
char	*get_next_line(int fd);
char	*read_lines(int fd, char *buffer);
char	*get_good_line(char *line);
char	*free_buff(char *ret, char *buffer);
char	*get_good_next(char *buffer);

// FREE
void	free_map(char ***map);
void	free_split(char **split);

// ERR
void	ft_return(char *error, int exit_code);

#endif