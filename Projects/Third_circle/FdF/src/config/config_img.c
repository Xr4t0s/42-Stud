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

void	configure_img(t_controller *multiplex)
{
	if (!multiplex || !multiplex->mlx_ptr || !multiplex->window)
		return ;
	multiplex->img.img = mlx_new_image(multiplex->mlx_ptr, multiplex->img.width, multiplex->img.height);
	multiplex->img.addr = mlx_get_data_addr(multiplex->img.img,
			&multiplex->img.bits_per_pixel,
			&multiplex->img.line_length,
			&multiplex->img.endian);
	draw_font(multiplex, 0xFFFFFF);
	draw_map(multiplex);
	mlx_put_image_to_window(multiplex->mlx_ptr, multiplex->window,
		multiplex->img.img,
		multiplex->width - multiplex->img.width - 10,
		multiplex->height - multiplex->img.height + 20);
}
