/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:25:20 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/15 23:25:20 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:25:20 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/15 23:25:20 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calculate_scale(t_controller *data)
{
	double	scale_x;
	double	scale_y;

	if (data->map.x == 0 || data->map.y == 0)
		return (10.0);
	scale_x = (double)data->img.width / (data->map.x * 2);
	scale_y = (double)data->img.height / (data->map.y * 2);
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

void	iso_projection(int *x, int *y, int z, double z_factor)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * COS_30;
	*y = (prev_x + prev_y) * SIN_30 - (z / z_factor);
}

t_point	project_point(t_controller *m, int x, int y)
{
	t_point	proj;
	int		z;

	z = m->map.coords[y * m->map.x + x] * (m->scale / 5);
	proj.x = x * m->scale;
	proj.y = y * m->scale;
	iso_projection(&proj.x, &proj.y, z, m->z_factor);
	proj.x += (m->img.width / 2) + m->offset_x;
	proj.y += (m->img.height / 3) + m->offset_y;
	return (proj);
}

void	draw_links(t_controller *m, t_point p, int x, int y)
{
	t_line	line;

	if (x + 1 < m->map.x)
	{
		line.p1 = p;
		line.p2 = project_point(m, x + 1, y);
		line.color = 0xFFFFFF;
		draw_line(&m->img, line);
	}
	if (y + 1 < m->map.y)
	{
		line.p1 = p;
		line.p2 = project_point(m, x, y + 1);
		line.color = 0xFFFFFF;
		draw_line(&m->img, line);
	}
}

void	draw_map(t_controller *m)
{
	int		x;
	int		y;
	t_point	proj;

	y = 0;
	while (y < m->map.y)
	{
		x = 0;
		while (x < m->map.x)
		{
			proj = project_point(m, x, y);
			put_pixel(&m->img, proj.x, proj.y, 0xFFFFFF);
			draw_links(m, proj, x, y);
			x++;
		}
		y++;
	}
}
