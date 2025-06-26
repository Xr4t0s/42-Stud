/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:16:22 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 02:20:58 by engiacom         ###   ########.fr       */
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
# include "free.h"
# include "raycast.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	t_map		map;
	t_mlx		mlx;
	t_player	player;
	t_minimap	minimap;
	t_raycast	raycast;
}	t_data;

#endif
