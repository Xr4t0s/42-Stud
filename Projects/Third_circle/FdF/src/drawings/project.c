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

void	project_iso(int *x, int *y, int z)
{
	int	prev_x = *x;
	int	prev_y = *y;
	*x = (prev_x - prev_y) * 20;
	*y = (prev_x + prev_y) * 10 - z * 5;
}


void	put_pixel(t_controller *multiplex, int x, int y, int color)
{
	char	*dst;

	if (!multiplex)
	{
		ft_printf("Erreur: img->addr est NULL\n");
		return;
	}
	 
	if (x < 0 || y < 0 || x >= multiplex->img.width || y >= multiplex->img.height)
		return ; // Évite d'écrire hors de l'image

	printf("Accès pixel : x=%d, y=%d, addr=%p, bpp=%d, line_length=%d\n",
		x, y, multiplex->img.addr, multiplex->img.bits_per_pixel, multiplex->img.line_length);
	dst = multiplex->img.addr + (y * multiplex->img.line_length + x * (multiplex->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void find_map_bounds(t_controller *controller, int *min_x, int *max_x, int *min_y, int *max_y)
{
	int x, y, index, x_proj, y_proj, z;

	*min_x = 10000;
	*max_x = -10000;
	*min_y = 10000;
	*max_y = -10000;

	for (y = 0; y < controller->map.y; y++)
	{
		for (x = 0; x < controller->map.x; x++)
		{
			index = y * controller->map.x + x;
			z = controller->map.coords[index];

			x_proj = x;
			y_proj = y;
			project_iso(&x_proj, &y_proj, z);

			if (x_proj < *min_x) *min_x = x_proj;
			if (x_proj > *max_x) *max_x = x_proj;
			if (y_proj < *min_y) *min_y = y_proj;
			if (y_proj > *max_y) *max_y = y_proj;
		}
	}
}

void	draw_line(t_controller *multiplex, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		put_pixel(multiplex, x0, y0, color);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; }
		if (e2 <= dx) { err += dx; y0 += sy; }
	}
}


void	draw_map(t_controller *controller)
{
	int x, y, index, x_proj, y_proj, z;
	int x_proj_right, y_proj_right, x_proj_down, y_proj_down, z_right, z_down;
	int min_x, max_x, min_y, max_y;

	// Trouver les limites de la carte projetée
	find_map_bounds(controller, &min_x, &max_x, &min_y, &max_y);
	int map_width = max_x - min_x;
	int map_height = max_y - min_y;
	int offset_x = (controller->img.width - map_width) / 2 - min_x;
	int offset_y = (controller->img.height - map_height) / 2 - min_y;

	for (y = 0; y < controller->map.y; y++)
	{
		for (x = 0; x < controller->map.x; x++)
		{
			index = y * controller->map.x + x;
			z = controller->map.coords[index];

			// Projeter le point courant
			x_proj = x;
			y_proj = y;
			project_iso(&x_proj, &y_proj, z);
			x_proj += offset_x;
			y_proj += offset_y;

			// Afficher le point
			put_pixel(controller, x_proj, y_proj, 0xFFFFFF);

			// Relier au point de droite s'il existe
			if (x + 1 < controller->map.x)
			{
				z_right = controller->map.coords[index + 1];
				x_proj_right = x + 1;
				y_proj_right = y;
				project_iso(&x_proj_right, &y_proj_right, z_right);
				x_proj_right += offset_x;
				y_proj_right += offset_y;

				draw_line(controller, x_proj, y_proj, x_proj_right, y_proj_right, 0xCCCCCC);
			}

			// Relier au point du bas s'il existe
			if (y + 1 < controller->map.y)
			{
				z_down = controller->map.coords[index + controller->map.x];
				x_proj_down = x;
				y_proj_down = y + 1;
				project_iso(&x_proj_down, &y_proj_down, z_down);
				x_proj_down += offset_x;
				y_proj_down += offset_y;

				draw_line(controller, x_proj, y_proj, x_proj_down, y_proj_down, 0xCCCCCC);
			}
		}
	}
}
