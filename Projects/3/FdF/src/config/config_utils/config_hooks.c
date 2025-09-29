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
