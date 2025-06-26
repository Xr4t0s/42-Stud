/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:10:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 00:20:42 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <fcntl.h>

typedef struct s_data t_data;

typedef struct s_direction
{
	void	*img;
	int		width;
	int		height;
}	t_direction;

typedef struct s_textures
{
	t_direction	no;
	t_direction	so;
	t_direction	we;
	t_direction	ea;
	int		fc[2][3];
}	t_textures;

typedef struct s_map
{
	int			fd_file;
	char		**map;
	int			width;
	int			height;
	t_textures	textures;
}	t_map;

// PARSING
int		parse_file(t_data *d, char *filename);
char	*remove_spaces(char *line);
void	normalize_map(t_data *d);
void	handle_no_so(t_data *d, char *trimed, int target);
void	handle_we_ea(t_data *d, char *trimed, int target);

// CHECK FUNCTIONS
int	check_data(t_data *d, char *filename);
int	check_map_data(t_data d);
int	check_param(t_data d);

#endif