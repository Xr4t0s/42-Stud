/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 22:07:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:43 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_draw(t_raycast *raycast, t_data *data,
	t_raydata *rd, t_draw *draw)
{
	draw->x0 = (int)(raycast->pos_x * data->scale + 1.5);
	draw->y0 = (int)(raycast->pos_y * data->scale);
	draw->x1 = (int)(rd->hitx * data->scale);
	draw->y1 = (int)(rd->hity * data->scale);
	draw->color = 0x00FFFF00;
	draw->dx = abs(draw->x1 - draw->x0);
	draw->dy = abs(draw->y1 - draw->y0);
	draw->err = draw->dx - draw->dy;
	if (draw->x0 < draw->x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (draw->y0 < draw->y1)
		draw->sy = 1;
	else
		draw->sy = -1;
}

void	draw_line(t_raycast *raycast, t_data *data, t_raydata *rd)
{
	t_draw	draw;

	init_draw(raycast, data, rd, &draw);
	while (1)
	{
		if (draw.x0 >= 0 && draw.y0 >= 0)
		{
			draw.pixel = rd->addr
				+ (draw.y0 * rd->line_len + draw.x0 * (rd->bpp / 8));
			*(unsigned int *)draw.pixel = draw.color;
		}
		if (draw.x0 == draw.x1 && draw.y0 == draw.y1)
			break ;
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.dy)
		{
			draw.err -= draw.dy;
			draw.x0 += draw.sx;
		}
		if (draw.e2 < draw.dx)
		{
			draw.err += draw.dx;
			draw.y0 += draw.sy;
		}
	}
}

unsigned int	rgb24(int fc[3])
{
	return ((fc[0] & 0xFF) << 16 | ((fc[1] & 0xFF) << 8) | (fc[2] & 0xFF));
}
