/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 06:37:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 01:03:04 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error bad arguments"), 1);
	init(&data);
	data.mlx.mlx = mlx_init();
	if (!check_data(&data, av[1]))
		return (
			free_all(&data),
			printf("error"), 0);
	for (int i = 0; data.map.map[i]; i++)
		printf("%s\n", data.map.map[i]);
	free_all(&data);
}
