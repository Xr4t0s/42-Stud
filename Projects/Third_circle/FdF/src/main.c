/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:53:58 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/10 14:53:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	deal_mouse_up(int button, int x, int y, void *param)
// {

// }

// int	deal_mouse_down(int button, int x, int y, void *param)
// {

// }

int	main(int ac, char **filename)
{
	t_controller	*multiplex;

	if (ac != 2)
		return (0);
	multiplex = (t_controller *)malloc(sizeof(t_controller));
	if (!multiplex)
		return (0);
	init_controller(multiplex, *(++filename));
	mlx_loop(multiplex->mlx_ptr);
	free_controller(multiplex);
	return (0);
}
