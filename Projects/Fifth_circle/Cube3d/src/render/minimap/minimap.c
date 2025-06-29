/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:46:34 by engiacom          #+#    #+#             */
/*   Updated: 2025/06/29 18:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "raycast.h"

void	minimap_draw_pixel(char *addr, int x, int y, int color, int bpp, int line_len)
{
	if (x >= 0 && x < 1080 && y >= 0 && y < 720)
	{
		char *dst = addr + (y * line_len + x * (bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	minimap(char **map, t_data *data, char *addr, int bpp, int line_len)
{
	int	x, y, px, py;
	int	size = 10;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			int color = 0x000000; // background par défaut

			if (map[y][x] == '1')
				color = 0x444444; // gris foncé pour mur
			else if (map[y][x] == '0')
				color = 0xAAAAAA; // gris clair pour sol
			else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				color = 0xAAAAAA; // vert pour joueur

			// dessine le bloc
			for (py = 0; py < size; py++)
			{
				for (px = 0; px < size; px++)
				{
					minimap_draw_pixel(addr, x * size + px, y * size + py, color, bpp, line_len);
				}
			}
			x++;
		}
		y++;
	}

	// Dessine le joueur comme un carré rouge 4x4 centré
	for (py = 0; py <= 3; py++)
		for (px = 0; px <= 3; px++)
			minimap_draw_pixel(addr, data->player.xP + px, data->player.yP + py, 0xFF0000, bpp, line_len);
}



