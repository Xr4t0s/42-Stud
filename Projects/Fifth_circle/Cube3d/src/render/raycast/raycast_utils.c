/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:53:40 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:32 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_side2(t_raydata *rd, t_raycast *raycast,
	t_data *data, t_direction **tex)
{
	(void)tex;
	if (rd->hit)
		rd->dist = raycast->perpwall_dist;
	else
		rd->dist = 1e9;
	if (rd->dist > 0.0)
		rd->line_height = (int)(data->mlx.height / rd->dist);
	else
		rd->line_height = data->mlx.height;
	rd->draw_start = (data->mlx.height - rd->line_height) / 2;
	rd->draw_end = rd->draw_start + rd->line_height - 1;
	if (rd->draw_start < 0)
		rd->draw_start = 0;
	if (rd->draw_end >= data->mlx.height)
		rd->draw_end = data->mlx.height - 1;
	rd->ceil_col = rgb24(data->map.textures.fc[0]);
	rd->floor_col = rgb24(data->map.textures.fc[1]);
}

void	init_tex_and_draw(t_raycast *raycast,
	t_raydata *rd, t_direction *tex, t_data *d)
{
	char	*p;

	p = NULL;
	if (raycast->side <= 1)
		rd->wallx = raycast->pos_y + rd->dist * raycast->raydir_y;
	else
		rd->wallx = raycast->pos_x + rd->dist * raycast->raydir_x;
	rd->wallx -= floor(rd->wallx);
	rd->tex_x = (int)(rd->wallx * tex->width);
	rd->step = (double)tex->height / (double)rd->line_height;
	rd->tex_pos = (rd->draw_start - d->mlx.height / 2.0
			+ rd->line_height / 2.0) * rd->step;
	rd->y = 0;
	while (rd->y < rd->draw_start)
	{
		p = rd->addr + (rd->y * rd->line_len + rd->x * (rd->bpp / 8));
		*(unsigned int *)p = rd->ceil_col;
		rd->y++;
	}
}

void	draw_wall(t_raydata *rd, t_direction *tex)
{
	unsigned int	color;
	char			*src;
	int				texy;
	char			*p;

	src = NULL;
	p = NULL;
	rd->y = rd->draw_start;
	while (rd->y <= rd->draw_end)
	{
		texy = (int)rd->tex_pos;
		if (texy < 0)
			texy = 0;
		if (texy >= tex->height)
			texy = tex->height - 1;
		rd->tex_pos += rd->step;
		src = tex->addr + texy * tex->line_len + rd->tex_x * (tex->bpp / 8);
		color = *(unsigned int *)src;
		p = rd->addr + (rd->y * rd->line_len + rd->x * (rd->bpp / 8));
		*(unsigned int *)p = color;
		rd->y++;
	}
}

void	draw_floor_and_put_screen(t_raydata *rd,
	t_raycast *raycast, t_data *data)
{
	char	*p;

	p = NULL;
	rd->y = rd->draw_end + 1;
	while (rd->y < data->mlx.height)
	{
		p = rd->addr + (rd->y * rd->line_len + rd->x * (rd->bpp / 8));
		*(unsigned int *)p = rd->floor_col;
		rd->y++;
	}
	rd->hitx = raycast->pos_x + raycast->raydir_x * rd->final_dist;
	rd->hity = raycast->pos_y + raycast->raydir_y * rd->final_dist;
	draw_line(raycast, data, rd);
	rd->x++;
}

void	all_checks(t_raycast *raycast,
	t_raydata *rd, t_data *data, t_direction *tex)
{
	tex = NULL;
	base_calc(raycast, data, rd);
	base_calc2(raycast);
	rd->hit = 0;
	rd->distance_travelled = 0.0f;
	while (rd->hit == 0 && rd->distance_travelled < MAX_DIST)
	{
		ray_check(raycast, rd, data);
		ray_check2(raycast, rd, data);
		ray_check3(raycast);
	}
	check_side(rd, raycast);
	check_side2(rd, raycast, data, &tex);
}
