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

void draw_map(t_controller *multiplex)
{
    int x, y;
    int x_proj, y_proj, x_proj_right, y_proj_right, x_proj_down, y_proj_down;
    int z, z_right, z_down;

    for (y = 0; y < multiplex->map.y; y++)
    {
        for (x = 0; x < multiplex->map.x; x++)
        {
            // Projection du point actuel
            z = multiplex->map.coords[y * multiplex->map.x + x] * (multiplex->scale / 5);
            x_proj = x * multiplex->scale;
            y_proj = y * multiplex->scale;
            iso_projection(&x_proj, &y_proj, z, multiplex->z_factor);

            // Dessiner le point
            put_pixel(&multiplex->img, (x_proj + multiplex->img.width / 2) + multiplex->offset_x, 
                      (y_proj + multiplex->img.height / 3) + multiplex->offset_y, 0xFFFFFF);

            // Relier à droite si possible
            if (x + 1 < multiplex->map.x)
            {
                z_right = multiplex->map.coords[y * multiplex->map.x + (x + 1)] * (multiplex->scale / 5);
                x_proj_right = (x + 1) * multiplex->scale;
                y_proj_right = y * multiplex->scale;
                iso_projection(&x_proj_right, &y_proj_right, z_right, multiplex->z_factor);
                draw_line(&multiplex->img, 
                          (x_proj + multiplex->img.width / 2) + multiplex->offset_x,
                          (y_proj + multiplex->img.height / 3) + multiplex->offset_y,
                          (x_proj_right + multiplex->img.width / 2) + multiplex->offset_x,
                          (y_proj_right + multiplex->img.height / 3) + multiplex->offset_y, 0xFFFFFF);
            }

            // Relier en bas si possible
            if (y + 1 < multiplex->map.y)
            {
                z_down = multiplex->map.coords[(y + 1) * multiplex->map.x + x] * (multiplex->scale / 5);
                x_proj_down = x * multiplex->scale;
                y_proj_down = (y + 1) * multiplex->scale;
                iso_projection(&x_proj_down, &y_proj_down, z_down, multiplex->z_factor);
                draw_line(&multiplex->img, 
                          (x_proj + multiplex->img.width / 2) + multiplex->offset_x,
                          (y_proj + multiplex->img.height / 3) + multiplex->offset_y,
                          (x_proj_down + multiplex->img.width / 2) + multiplex->offset_x,
                          (y_proj_down + multiplex->img.height / 3) + multiplex->offset_y, 0xFFFFFF);
            }
        }
    }
}
