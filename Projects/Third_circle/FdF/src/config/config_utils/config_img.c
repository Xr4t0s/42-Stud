/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:15:09 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/15 19:15:09 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		ft_return("Erreur dans put_pixel():20", 0, (void *)0);
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_font(t_controller *multiplex)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < multiplex->img.height - 30)
	{
		while (x < multiplex->img.width)
		{
			if (x == 0 || x == multiplex->img.width - 1 || y == 0
				|| y == multiplex->img.height - 31)
				put_pixel(&multiplex->img, x, y, 0xFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(multiplex->mlx_ptr,
		multiplex->window,
		10,
		15,
		0xFFFFFF,
		"Press ESC to quit");
	mlx_string_put(multiplex->mlx_ptr, multiplex->window, 10, 35,
		0xFFFFFF, "Welcome to my FDF project");
}

void	configure_img(t_controller *multiplex)
{
	if (!multiplex || !multiplex->mlx_ptr || !multiplex->window)
		return ;
	multiplex->img.img = mlx_new_image(multiplex->mlx_ptr, multiplex->img.width,
			multiplex->img.height);
	multiplex->img.addr = mlx_get_data_addr(multiplex->img.img,
			&multiplex->img.bits_per_pixel,
			&multiplex->img.line_length,
			&multiplex->img.endian);
	draw_font(multiplex);
	draw_map(multiplex);
	mlx_put_image_to_window(multiplex->mlx_ptr, multiplex->window,
		multiplex->img.img,
		multiplex->width - multiplex->img.width - 10,
		multiplex->height - multiplex->img.height + 20);
}
