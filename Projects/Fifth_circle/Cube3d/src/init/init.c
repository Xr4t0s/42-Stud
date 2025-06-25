/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:15:14 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/25 07:38:50 by nitadros         ###   ########.fr       */
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
}

void	init(t_data *data)
{
	init_map(&data->map);
	init_player(&data->player);
}
