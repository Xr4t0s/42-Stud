/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:17:11 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/18 03:06:48 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "raycast.h"
#include <math.h>

#define MAX_DIST 5.0

void	draw_line(char *addr, int x0, int y0, int x1, int y1, int color, int bpp, int line_len)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = (x0 < x1) ? 1 : -1;
	int	sy = (y0 < y1) ? 1 : -1;
	int	err = dx - dy;

	while (1)
	{
		if (x0 >= 0 && y0 >= 0)
		{
			char *pixel = addr + (y0 * line_len + x0 * (bpp / 8));
			*(unsigned int *)pixel = color;
		}
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x0 += sx; }
		if (e2 < dx) { err += dx; y0 += sy; }
	}
}

int	render(void *param)
{
	t_data	*data = (t_data *)param;
	static void *img = NULL;
	static char *addr;
	static int bpp, line_len, endian;

	if (!img)
	{
		img = mlx_new_image(data->mlx.mlx, 1080, 720);
		addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	}
	minimap(data->map.map, data, addr, bpp, line_len);

	int x = 0;
	while (x < 1080)
	{
		t_raycast raycast;

		raycast.posX = data->player.xP / 10.0;
		raycast.posY = data->player.yP / 10.0;

		raycast.dirX = cos(data->player.angle);// X = 0 Y = -1 == NORTH
		raycast.dirY = sin(data->player.angle);
		
		raycast.planeX = -raycast.dirY * tan(data->player.fov/2); // same here
		raycast.planeY = raycast.dirX * tan(data->player.fov/2);

		raycast.cameraX = 2 * x / (float)1080 - 1;
		 
		raycast.rayDirX = raycast.dirX + raycast.planeX * raycast.cameraX;
		raycast.rayDirY = raycast.dirY + raycast.planeY * raycast.cameraX;

		raycast.mapX = (int)raycast.posX;
		raycast.mapY = (int)raycast.posY;

		raycast.deltaDistX = fabs(1 / raycast.rayDirX);
		raycast.deltaDistY = fabs(1 / raycast.rayDirY);

		raycast.stepX = (raycast.rayDirX < 0) ? -1 : 1;
		raycast.stepY = (raycast.rayDirY < 0) ? -1 : 1;

		raycast.sideDistX = (raycast.rayDirX < 0)
			? (raycast.posX - raycast.mapX) * raycast.deltaDistX
			: (raycast.mapX + 1.0 - raycast.posX) * raycast.deltaDistX;
		raycast.sideDistY = (raycast.rayDirY < 0)
			? (raycast.posY - raycast.mapY) * raycast.deltaDistY
			: (raycast.mapY + 1.0 - raycast.posY) * raycast.deltaDistY;

		int hit = 0;
		float distance_travelled = 0;

		while (!hit && distance_travelled < MAX_DIST)
		{
			if (raycast.sideDistX < raycast.sideDistY)
			{
				distance_travelled = raycast.sideDistX;
				raycast.sideDistX += raycast.deltaDistX;
				raycast.mapX += raycast.stepX;
				raycast.side = 0;
			}
			else
			{
				distance_travelled = raycast.sideDistY;
				raycast.sideDistY += raycast.deltaDistY;
				raycast.mapY += raycast.stepY;
				raycast.side = 1;
			}
			if (data->map.map[raycast.mapY][raycast.mapX] == '1')
				hit = 1;
		}

		
		float hitX, hitY;
		float finalDist;
		if (hit)
		{
			if (raycast.side == 0)
				raycast.perpWallDist = (raycast.mapX - raycast.posX + (1 - raycast.stepX) / 2) / raycast.rayDirX;
			else
				raycast.perpWallDist = (raycast.mapY - raycast.posY + (1 - raycast.stepY) / 2) / raycast.rayDirY;

			finalDist = fmin(raycast.perpWallDist, MAX_DIST);
		}
		else
			finalDist = MAX_DIST;

		hitX = raycast.posX + raycast.rayDirX * finalDist;
		hitY = raycast.posY + raycast.rayDirY * finalDist;


		draw_line(addr,
			raycast.posX * 10 + 1.5, raycast.posY * 10,
			hitX * 10, hitY * 10,
			0x00FFFF00, bpp, line_len);

		x++;
	}

	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, img, 0, 0);
	return (0);
}
