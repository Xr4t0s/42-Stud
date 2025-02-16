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


/* Here we init mouse struct */
static void init_mouse(t_controller *multiplex)
{
	if (!multiplex)
		return ;
	multiplex->mouse.is_pressed = 0;
	multiplex->mouse.x = 0;
	multiplex->mouse.y = 0;
	multiplex->mouse.previous_x = 0;
	multiplex->mouse.previous_y = 0;
}

/* Here we init map struct */
static void init_map(t_controller *multiplex)
{
	if (!multiplex)
		return ;
	multiplex->map.x = 0;
	multiplex->map.y = 0;
	multiplex->map.index = 0;
	multiplex->map.coords = NULL;
}

/* Here we init img struct */
static void	init_img(t_controller *multiplex)
{
	if (!multiplex)
		return ;
	multiplex->img.img = NULL;
	multiplex->img.addr = NULL;
	multiplex->img.bits_per_pixel = 0;
	multiplex->img.line_length = 0;
	multiplex->img.endian = 0;
	multiplex->img.width = 680;
	multiplex->img.height = 680;
}

/* Here we init all components */
static void	init_components(t_controller *multiplex)
{
	if (!multiplex)
		return ;
	init_img(multiplex);
	init_map(multiplex);
	init_mouse(multiplex);
	multiplex->next = NULL;
}

/* 	Here we init the principal controller :
		- First we init multiplex->mlx_ptr, multiplex->window,
	and multiplex->filename
		- Then we call the init_components() function, that init
	img, map, and mouse struct of the multiplex controller
*/
void	init_controller(t_controller *multiplex, char *filename)
{
	if (!multiplex || !filename)
		ft_return("Error while initializing controller", 0, multiplex);
	multiplex->filename = NULL;
	multiplex->mlx_ptr = NULL;
	multiplex->window = NULL;
	multiplex->width = 700;
	multiplex->height = 700;
	init_components(multiplex);
	multiplex->mlx_ptr = mlx_init();
	if (!multiplex->mlx_ptr)
		ft_return("Error with mlx_init() init.c:44", 0, multiplex);
	multiplex->window = mlx_new_window(multiplex->mlx_ptr,
			multiplex->width, multiplex->height, "FDF");
	multiplex->filename = filename;
}
