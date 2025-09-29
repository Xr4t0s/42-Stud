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

int	main(int ac, char **filename)
{
	t_controller	*multiplex;

	if (ac != 2)
		return (0);
	multiplex = (t_controller *)malloc(sizeof(t_controller));
	if (!multiplex)
		return (0);
	init_controller(multiplex, *(++filename));
	parse_map(*filename, multiplex);
	configure_all(multiplex);
	mlx_loop(multiplex->mlx_ptr);
	free_controller(multiplex);
	return (0);
}
