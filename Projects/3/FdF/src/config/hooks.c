/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:55:37 by nitadros          #+#    #+#             */
/*   Updated: 2025/03/01 15:55:37 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_key_events(int key, t_controller *multiplex)
{
	if (key == ESC_KEY)
		ft_return("It's ok don't worry", 1, multiplex);
	if (key == 65451)
		multiplex->scale *= 1.1;
	if (key == 65453 && multiplex->scale > 1.5)
		multiplex->scale /= 1.1;
	if (key == 119 && multiplex->z_factor > 0.5)
		multiplex->z_factor -= 0.5;
	if (key == 115)
		multiplex->z_factor += 0.5;
	if (key == 65361)
		multiplex->offset_x -= 10;
	if (key == 65363)
		multiplex->offset_x += 10;
	if (key == 65362)
		multiplex->offset_y -= 10;
	if (key == 65364)
		multiplex->offset_y += 10;
}

static void	refresh_display(t_controller *multiplex)
{
	if (multiplex->img.img)
		mlx_destroy_image(multiplex->mlx_ptr, multiplex->img.img);
	multiplex->img.img = mlx_new_image(multiplex->mlx_ptr,
			multiplex->img.width, multiplex->img.height);
	if (!multiplex->img.img)
		ft_return("Error in function refresh_display()", 0, multiplex);
	mlx_clear_window(multiplex->mlx_ptr, multiplex->window);
	draw_font(multiplex);
	draw_map(multiplex);
	mlx_put_image_to_window(multiplex->mlx_ptr, multiplex->window,
		multiplex->img.img,
		multiplex->width - multiplex->img.width - 10,
		multiplex->height - multiplex->img.height + 20);
}

int	deal_key(int key, t_controller *multiplex)
{
	ft_printf("Typed on keyboard: %d\n", key);
	handle_key_events(key, multiplex);
	refresh_display(multiplex);
	return (0);
}
