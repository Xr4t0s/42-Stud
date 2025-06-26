/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:05:15 by engiacom          #+#    #+#             */
/*   Updated: 2025/06/26 03:17:32 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "raycast.h"

int	render(void *param)
{
	t_data	*data = (t_data *)param;
	static void *img = NULL;
	static char *addr;
	static int bpp, line_len, endian;
	
	// Crée l'image 1 seule fois
	if (!img)
	{
		img = mlx_new_image(data->mlx.mlx, 1080, 720);
		addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	}
	
	// Dessin du carré rouge centré
	int start_x = (1080 - 100) / 2;
	int start_y = (720 - 100) / 2;
	for (int y = start_y; y < start_y + 100; y++)
	{
		for (int x = start_x; x < start_x + 100; x++)
		{
			if (x >= 0 && x < 1080 && y >= 0 && y < 720)
			{
				char *dst = addr + (y * line_len + x * (bpp / 8));
				*(unsigned int *)dst = 0x00FF0000; // rouge
			}
		}
	}
	
	minimap(data->map.map, data, addr, bpp, line_len);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, img, 0, 0);
	return (0);
}
