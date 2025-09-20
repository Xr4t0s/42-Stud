/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:15:14 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/20 19:52:31 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->fd_file = 0;
	map->map = malloc(sizeof(char *) * 101);
	if (!map->map)
		return ;
	map->width = 0;
	map->height = 0;
	map->textures.no.img = NULL;
	map->textures.so.img = NULL;
	map->textures.we.img = NULL;
	map->textures.ea.img = NULL;
	while (j < 2)
	{
		while (i < 3)
		{
			map->textures.fc[j][i] = -1;
			i++;
		}
		i = 0;
		j++;
	}
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->xP = 0;
	player->y = 0;
	player->yP = 0;
	player->angle = 2.355;
	player->fov = 1.1519;
	player->fov_rot = 0.05;
	player->rot = 0.05;
	player->move_speed = 1.5;
}

int	init_txt(t_data *data)
{
	int	h;
	int	w;
	
	data->minimap.player = mlx_xpm_file_to_image(data->mlx.mlx, "src/render/minimap/textures/player.xpm", &w, &h);
	data->minimap.bg = mlx_xpm_file_to_image(data->mlx.mlx, "src/render/minimap/textures/white.xpm", &w, &h);
	data->minimap.wall = mlx_xpm_file_to_image(data->mlx.mlx, "src/render/minimap/textures/blue.xpm", &w, &h);
	data->minimap.bg4 = mlx_xpm_file_to_image(data->mlx.mlx, "src/render/minimap/textures/bg4.xpm", &w, &h);
	return (1);
}
void	init(t_data *data)
{
	init_map(&data->map);
	init_player(&data->player);
	init_txt(data);
	data->raycast.door = -1;
}
