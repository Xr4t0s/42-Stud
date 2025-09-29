/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:17:11 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 22:28:06 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"
#include <math.h>

void	init_ray(t_raydata *rd, t_data *data)
{
	mlx_hook(data->mlx.win, 17, 0, close_window, data);
	handle_keypress(0, data);
	if (rd->img == NULL)
	{
		rd->img = mlx_new_image(data->mlx.mlx, data->mlx.width,
				data->mlx.height);
		rd->addr = mlx_get_data_addr(rd->img, &rd->bpp,
				&rd->line_len, &rd->endian);
	}
	rd->x = 0;
}

void	base_calc(t_raycast *raycast, t_data *data, t_raydata *rd)
{
	raycast->pos_x = data->player.xp / data->scale;
	raycast->pos_y = data->player.yp / data->scale;
	raycast->dir_x = cos(data->player.angle);
	raycast->dir_y = sin(data->player.angle);
	raycast->plane_x = -raycast->dir_y * tan(data->player.fov / 2);
	raycast->plane_y = raycast->dir_x * tan(data->player.fov / 2);
	raycast->camera_x = 2.0f * (float)rd->x / (float)data->mlx.width - 1.0f;
	raycast->raydir_x = raycast->dir_x + raycast->plane_x * raycast->camera_x;
	raycast->raydir_y = raycast->dir_y + raycast->plane_y * raycast->camera_x;
	raycast->map_x = (int)raycast->pos_x;
	raycast->map_y = (int)raycast->pos_y;
	raycast->deltadist_x = fabs(1.0 / raycast->raydir_x);
	raycast->deltadist_y = fabs(1.0 / raycast->raydir_y);
}

void	base_calc2(t_raycast *raycast)
{
	if (raycast->raydir_x < 0)
		raycast->step_x = -1;
	else
		raycast->step_x = 1;
	if (raycast->raydir_y < 0)
		raycast->step_y = -1;
	else
		raycast->step_y = 1;
	if (raycast->raydir_x < 0)
		raycast->sidedist_x = (raycast->pos_x - raycast->map_x)
			* raycast->deltadist_x;
	else
		raycast->sidedist_x = (raycast->map_x + 1.0 - raycast->pos_x)
			* raycast->deltadist_x;
	if (raycast->raydir_y < 0)
		raycast->sidedist_y = (raycast->pos_y - raycast->map_y)
			* raycast->deltadist_y;
	else
		raycast->sidedist_y = (raycast->map_y + 1.0 - raycast->pos_y)
			* raycast->deltadist_y;
}

void	ending(t_data *data, t_raydata *rd)
{
	data->raycast.door = -1;
	minimap(data, rd->addr, rd->bpp, rd->line_len);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, rd->img, 0, 0);
	mlx_destroy_image(data->mlx.mlx, rd->img);
}

int	render(void *param)
{
	t_data				*data;
	t_raydata			rd;
	t_direction			*tex;
	static t_raycast	raycast;

	data = (t_data *)param;
	rd.img = NULL;
	init_ray(&rd, data);
	while (rd.x < data->mlx.width)
	{
		all_checks(&raycast, &rd, data, tex);
		if (raycast.side == 1)
			tex = &data->map.textures.ea;
		else if (raycast.side == 2)
			tex = &data->map.textures.no;
		else if (raycast.side == 3)
			tex = &data->map.textures.so;
		else
			tex = &data->map.textures.we;
		init_tex_and_draw(&raycast, &rd, tex, data);
		draw_wall(&rd, tex);
		draw_floor_and_put_screen(&rd, &raycast, data);
	}
	ending(data, &rd);
	return (0);
}
