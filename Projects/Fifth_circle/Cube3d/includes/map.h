/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:10:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/24 09:04:13 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "mlx.h"
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
	t_textures	textures;
}	t_map;

// PARSING UTILS
char	*remove_spaces(char *line);
void	handle_no(t_data *d, char *trimed);
void	handle_so(t_data *d, char *trimed);
void	handle_we(t_data *d, char *trimed);
void	handle_ea(t_data *d, char *trimed);

#endif