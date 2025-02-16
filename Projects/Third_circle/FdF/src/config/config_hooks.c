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

/* 	
	Fonction to deal with ESC_KEY and close the window
	For that we call mlx_key_hook() to interprets key press using
	this functuion.
*/
static int	deal_key(int key, t_controller *multiplex)
{
	ft_printf("Typed on keyboard\n");
	if (key == ESC_KEY)
		mlx_loop_end(multiplex->mlx_ptr);
	return (1);
}

/*
	Fonction who deals with the DestroyNotify signal.
	So we have to close the window.
	We used mlx_hook() here, which is more advanced than de mlx_key_hook()
	because you can customize what signal you will receive and how to react.
*/
static int	close_window(t_controller *multiplex)
{
	mlx_loop_end(multiplex->mlx_ptr);
	ft_return("Close window with DestroyNotify", 1, multiplex);
	return (1);
}

/*
	Function which will prevent resize of the window
	Correct it
*/
static int	prevent_resizing(t_controller *multiplex)
{
	ft_printf("Yes we enter here\n");
	mlx_clear_window(multiplex->mlx_ptr, multiplex->window);
	configure_img(multiplex);
	return (1);
}

void configure_hooks(t_controller *multiplex)
{
	mlx_key_hook(multiplex->window, deal_key, multiplex);
	mlx_hook(multiplex->window, 17, 0, close_window, multiplex);
	mlx_hook(multiplex->window, 25, (1L<<18), prevent_resizing, multiplex);
}
