/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 06:37:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/25 10:04:30 by nitadros         ###   ########.fr       */
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
	parse_file(&data, av[1]);
	for (int i = 0; data.map.map[i]; i++)
		printf("%s\n", data.map.map[i]);
	if (!check_map_data(data))
		return (printf("Data is false\n"));
	mlx_destroy_image(data.mlx.mlx, data.map.textures.no.img);
	mlx_destroy_display(data.mlx.mlx);
	free(data.mlx.mlx);
	ft_free_split(data.map.map);
}
