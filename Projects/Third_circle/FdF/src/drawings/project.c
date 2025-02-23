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
	double	scale;

	if (data->map.x == 0 || data->map.y == 0)
		return (10.0);
	scale_x = (double)data->img.width / (data->map.x * 2);
	scale_y = (double)data->img.height / (data->map.y * 2);
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < 2.0)
		scale = 2.0;
	return (scale);
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

void	draw_map(t_controller *multiplex)
{
	int	x;
	int	y;
	int	x_proj;
	int	y_proj;
	int	z;

	x = 0;
	y = 0;
	while (y < multiplex->map.y)
	{
		while (x < multiplex->map.x)
		{
			x_proj = x * multiplex->scale;
			y_proj = y * multiplex->scale;
			z = multiplex->map.coords[y * multiplex->map.x + x]
				* (multiplex->scale / 5);
			iso_projection(&x_proj, &y_proj, z, multiplex->z_factor);
			put_pixel(&multiplex->img, (x_proj + multiplex->img.width / 2)
				+ multiplex->offset_x, (y_proj + multiplex->img.height / 3)
				+ multiplex->offset_y, 0xFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}
