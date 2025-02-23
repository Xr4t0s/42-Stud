/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:13:54 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/15 19:13:54 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	deal_key(int key, t_controller *multiplex)
{
	ft_printf("Typed on keyboard: %d\n", key);
	if (key == ESC_KEY)
		ft_return("It's ok don't worry", 1, multiplex);
	else if (key == 65451)
		multiplex->scale *= 1.1;
	else if (key == 65453 && multiplex->scale > 1.5)
		multiplex->scale /= 1.1;
	else if (key == 119 && multiplex->z_factor > 0.5)
		multiplex->z_factor -= 0.5;
	else if (key == 115)
		multiplex->z_factor += 0.5;
	else if (key == 65361)
		multiplex->offset_x -= 10;
	else if (key == 65363)
		multiplex->offset_x += 10;
	else if (key == 65362)
		multiplex->offset_y -= 10;
	else if (key == 65364)
		multiplex->offset_y += 10;
	if (multiplex->img.img)
		mlx_destroy_image(multiplex->mlx_ptr, multiplex->img.img);
	multiplex->img.img = mlx_new_image(multiplex->mlx_ptr,
			multiplex->img.width, multiplex->img.height);
	if (!multiplex->img.img)
		ft_return("Error in function deal_key():58", 0, multiplex);
	mlx_clear_window(multiplex->mlx_ptr, multiplex->window);
	draw_font(multiplex);
	draw_map(multiplex);
	mlx_put_image_to_window(multiplex->mlx_ptr, multiplex->window,
		multiplex->img.img,
		multiplex->width - multiplex->img.width - 10,
		multiplex->height - multiplex->img.height + 20);
	return (0);
}

static int	close_window(t_controller *multiplex)
{
	mlx_loop_end(multiplex->mlx_ptr);
	ft_return("Close window with DestroyNotify", 1, multiplex);
	return (1);
}

static int	prevent_resizing(t_controller *multiplex)
{
	ft_printf("Yes we enter here\n");
	mlx_clear_window(multiplex->mlx_ptr, multiplex->window);
	mlx_destroy_window(multiplex->mlx_ptr, multiplex->window);
	multiplex->window = mlx_new_window(multiplex->mlx_ptr,
			multiplex->width, multiplex->height, "FDF");
	configure_all(multiplex);
	return (1);
}

void	configure_hooks(t_controller *multiplex)
{
	mlx_key_hook(multiplex->window, deal_key, multiplex);
	mlx_hook(multiplex->window, 17, 0, close_window, multiplex);
	mlx_hook(multiplex->window, 25, (1L << 18),
		prevent_resizing, multiplex);
}
