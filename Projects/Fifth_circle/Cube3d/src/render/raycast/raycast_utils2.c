/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:53:40 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:36 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_check(t_raycast *raycast, t_raydata *rd, t_data *data)
{
	if (raycast->sidedist_x < raycast->sidedist_y)
	{
		rd->distance_travelled = raycast->sidedist_x;
		raycast->sidedist_x += raycast->deltadist_x;
		raycast->map_x += raycast->step_x;
		raycast->side = 0;
	}
	else
	{
		rd->distance_travelled = raycast->sidedist_y;
		raycast->sidedist_y += raycast->deltadist_y;
		raycast->map_y += raycast->step_y;
		raycast->side = 2;
	}
	if (data->map.map[raycast->map_y][raycast->map_x] == '1'
		|| data->map.map[raycast->map_y][raycast->map_x] == 'D')
		rd->hit = 1;
}

void	ray_check2(t_raycast *raycast, t_raydata *rd, t_data *data)
{
	if (data->map.map[raycast->map_y][raycast->map_x] == 'D'
		&& data->raycast.door > 0 && (fabs(raycast->sidedist_x) <= 2
		|| fabs(raycast->sidedist_y) <= 2) && raycast->camera_x >= -0.30
		&& raycast->camera_x <= 0.30)
	{
		data->map.map[raycast->map_y][raycast->map_x] = '*';
		data->raycast.door *= -1;
		rd->hit = 0;
	}
	else if (data->map.map[raycast->map_y][raycast->map_x] == '*'
		&& data->raycast.door > 0 && (fabs(raycast->sidedist_x) <= 2
		|| fabs(raycast->sidedist_y) <= 2) && raycast->camera_x >= -0.30
		&& raycast->camera_x <= 0.30)
	{
		data->map.map[raycast->map_y][raycast->map_x] = 'D';
		data->raycast.door *= -1;
		rd->hit = 1;
	}
}

void	ray_check3(t_raycast *raycast)
{
	if (raycast->side == 2)
	{
		if (raycast->pos_y > raycast->map_y)
			raycast->side = 3;
	}
	else
	{
		if (raycast->pos_x > raycast->map_x)
			raycast->side = 1;
	}
}

void	check_side(t_raydata *rd, t_raycast *raycast)
{
	rd->hitx = raycast->pos_x + raycast->sidedist_x * raycast->raydir_x;
	rd->hity = raycast->pos_y + raycast->sidedist_y * raycast->raydir_y;
	if (rd->hit)
	{
		if (raycast->side <= 1)
		{
			raycast->perpwall_dist = (raycast->map_x - raycast->pos_x
					+ (1 - raycast->step_x) / 2.0) / raycast->raydir_x;
		}
		else
		{
			raycast->perpwall_dist = (raycast->map_y - raycast->pos_y
					+ (1 - raycast->step_y) / 2.0) / raycast->raydir_y;
		}
		if (raycast->perpwall_dist < MAX_DIST)
			rd->final_dist = raycast->perpwall_dist;
		else
			rd->final_dist = MAX_DIST;
	}
	else
	{
		rd->final_dist = MAX_DIST;
	}
}
