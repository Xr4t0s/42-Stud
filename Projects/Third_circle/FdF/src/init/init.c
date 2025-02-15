/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:29 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/13 17:48:29 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_controller *multiplex)
{
	ft_printf("Typed on keyboard\n");
	if (key == ESC_KEY)
		mlx_loop_end(multiplex->mlx_ptr);
	return (1);
}

static void	init_window(t_controller *multiplex)
{
	multiplex->mlx_ptr = NULL;
	multiplex->window = NULL;
}

static void	init_img(t_imgdata	*img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

static void	init_map(t_map *map)
{
	if (!map)
		return ;
	map->x = 0;
	map->y = 0;
	map->z = 0;
	map->index = 0;
	map->coords = NULL;
}

void	init_controller(t_controller *multiplex, char *filename)
{
	if (!multiplex || !filename)
		ft_return("Error while initializing controller", 0, multiplex);
	init_window(multiplex);
	init_img(&multiplex->img);
	init_map(&multiplex->map);
	multiplex->mlx_ptr = mlx_init();
	if (!multiplex->mlx_ptr)
		ft_return("Error with mlx_init() init.c:44", 0, multiplex);
	multiplex->window = mlx_new_window(multiplex->mlx_ptr,
			1080, 890, "FDF");
	multiplex->filename = filename;
	parse_map(filename, multiplex);
	multiplex->img.img = mlx_new_image(multiplex->mlx_ptr, 500, 500);
	multiplex->img.addr = mlx_get_data_addr(multiplex->img.img,
			&multiplex->img.bits_per_pixel,
			&multiplex->img.line_length,
			&multiplex->img.endian);
	mlx_key_hook(multiplex->window, deal_key, multiplex);
}
