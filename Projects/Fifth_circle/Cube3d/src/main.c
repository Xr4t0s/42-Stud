/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 06:37:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 15:48:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "raycast.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error bad arguments"), 1);
	data.mlx.mlx = mlx_init();
	if (!data.mlx.mlx) return (0);
	init(&data);
	if (!check_data(&data, av[1]))
		return (
			free_all(&data),
			printf("error"), 0);
	// for (int i = 0; data.map.map[i]; i++)
	// 	printf("%s\n", data.map.map[i]);
	data.mlx.win = mlx_new_window(data.mlx.mlx, 1080, 720, "Hello");
	movements(&data);
	mlx_loop_hook(data.mlx.mlx, render, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
}
