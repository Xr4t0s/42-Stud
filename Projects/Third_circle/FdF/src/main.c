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

void	init_mlx(t_window	**window)
{
	(*window)->mlx_ptr = NULL;
	(*window)->window = NULL;
}

void	start_win(char *filename)
{
	t_window	*mlx;

	mlx = malloc(sizeof(t_window));
	init_mlx(&mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx_ptr, 500, 500, ft_strjoin("FDF - ", filename));
	mlx_loop(mlx->mlx_ptr);
}

int main(int ac, char **filename)
{
	t_map	*map;

	if (ac != 2)
		return (0);
	map = parse_map(*(++filename));
	start_win(*filename);
	ft_printf("Success = %d\n", map->coords[0]);
	return (0);
}
