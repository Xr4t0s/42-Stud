/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:10:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:54:11 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>

typedef struct s_data	t_data;

typedef struct s_normalize
{
	int		i;
	int		j;
	char	**copy;
	int		count;
}	t_normalize;

typedef struct s_parsing
{
	int		i;
	char	*line;
	char	*trimed;
	int		(*ft)(const char *, const char *, size_t);
}	t_parsing;

typedef struct s_direction
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_direction;

typedef struct s_textures
{
	t_direction	no;
	t_direction	so;
	t_direction	we;
	t_direction	ea;
	int			fc[2][3];
}	t_textures;

typedef struct s_map
{
	int			fd_file;
	char		**map;
	int			width;
	int			height;
	t_textures	textures;
}	t_map;

typedef struct s_rm_char
{
	int		i;
	int		x;
	int		mark;
	char	*ret;
}	t_rm_char;

// PARSING
int		parse_file(t_data *d, char *filename);
int		loop_parse_file(t_parsing *t, t_data *d);
char	*parse_map(t_data *d, char *line, int *i);
char	*remove_spaces(char *line);
int		normalize_map(t_data *d, int index);
void	handle_no_so(t_data *d, char *trimed, int target);
void	handle_we_ea(t_data *d, char *trimed, int target);
int		fulfill_fc(char **param, t_data *d);
void	establish_map_size(t_data *d);
int		check_if_others_char(t_map *map);
char	*ft_rm_char(char *str, char *ch);

// CHECK FUNCTIONS
int		check_data(t_data *d, char *filename);
int		check_map_data(t_data d);
int		check_param(t_data d);
int		check_img(char *filename, t_data *d);

#endif