/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:16:22 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/21 01:49:46 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdio.h>
# include "libs/libft.h"
# include "libs/get_next_line.h"
# include "libs/get_next_line_bonus.h"
# include "libs/mlx.h"
# include "init.h"
# include "map.h"
# include "player.h"
# include "movements.h"
# include "free.h"
# include "raycast.h"
# include "math.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_data
{
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_minimap	minimap;
	t_raycast	raycast;
	t_move		move;
	t_mouse		mouse;
}	t_data;

#endif
