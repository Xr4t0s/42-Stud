/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:46:28 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/15 17:46:28 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	put_pixel(t_imgdata *img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (!img || !img->addr)
// 	{
// 		ft_printf("Erreur: img->addr est NULL\n");
// 		return;
// 	}
	 
// 	if (x < 0 || y < 0 || x >= IMG_WIDTH || y >= IMG_HEIGHT)
// 		return ; // Évite d'écrire hors de l'image

// 	printf("Accès pixel : x=%d, y=%d, addr=%p, bpp=%d, line_length=%d\n",
// 		x, y, img->addr, img->bits_per_pixel, img->line_length);
// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

/* ChatGPT function, need to take a look */
void	draw_font(t_controller *controller, int color)
{
	int x, y;

	for (y = 0; y < controller->img.height - 30; y++)
	{
		for (x = 0; x < controller->img.width; x++)
		{
			if (x == 0 || x == controller->img.width - 1 || y == 0 || y == controller->img.height - 31)
				put_pixel(controller, x, y, color);
		}
	}
	mlx_string_put(controller->mlx_ptr, controller->window, 10, 15, 0xFFFFFF, "Welcome to my fdf project");
}
