/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:44:50 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/14 21:44:50 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_controller(t_controller *multiplex)
{
	mlx_destroy_image(multiplex->mlx_ptr, multiplex->img.img);
	mlx_destroy_window(multiplex->mlx_ptr, multiplex->window);
	mlx_destroy_display(multiplex->mlx_ptr);
	if (multiplex->mlx_ptr)
		free(multiplex->mlx_ptr);
	free(multiplex->map.coords);
	free(multiplex);
}
