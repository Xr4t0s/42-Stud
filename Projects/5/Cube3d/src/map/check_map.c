/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 06:54:02 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 23:40:31 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_check(char **map, int i, int j)
{
	if (i < 0 || j < 0 || map[i] == NULL || map[i][j] == '\0')
		return (0);
	else if (map[i][j] == '.')
		return (0);
	else if (map[i][j] == '1' || map[i][j] == '*')
		return (1);
	map[i][j] = '*';
	return (flood_check(map, i + 1, j)
		&& flood_check(map, i - 1, j)
		&& flood_check(map, i, j + 1)
		&& flood_check(map, i, j - 1)
		&& flood_check(map, i + 1, j + 1)
		&& flood_check(map, i - 1, j - 1)
		&& flood_check(map, i - 1, j + 1)
		&& flood_check(map, i + 1, j - 1)
	);
}

static int	flood_check_dot(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j])
		return (1);
	if (map[i][j] == '0')
		return (0);
	if (map[i][j] == '1' || map[i][j] == ',')
		return (1);
	map[i][j] = ',';
	return (flood_check_dot(map, i + 1, j)
		&& flood_check_dot(map, i - 1, j)
		&& flood_check_dot(map, i, j + 1)
		&& flood_check_dot(map, i, j - 1)
		&& flood_check_dot(map, i + 1, j + 1)
		&& flood_check_dot(map, i - 1, j - 1)
		&& flood_check_dot(map, i - 1, j + 1)
		&& flood_check_dot(map, i + 1, j - 1)
	);
}

static int	flood_check_zero(char **map, int i, int j)
{
	if (i < 0 || j < 0 || !map[i] || !map[i][j])
		return (0);
	if (map[i][j] == '1' || map[i][j] == '/')
		return (1);
	map[i][j] = '/';
	return (flood_check_zero(map, i + 1, j)
		&& flood_check_zero(map, i - 1, j)
		&& flood_check_zero(map, i, j + 1)
		&& flood_check_zero(map, i, j - 1)
		&& flood_check_zero(map, i + 1, j + 1)
		&& flood_check_zero(map, i - 1, j - 1)
		&& flood_check_zero(map, i - 1, j + 1)
		&& flood_check_zero(map, i + 1, j - 1)
	);
}

int	check_map_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.')
			{
				if (!flood_check_dot(map, i, j))
					return (0);
			}
			if (map[i][j] == '0')
			{
				if (!flood_check_zero(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_data(t_data d)
{
	char	**copy;

	if (!d.map.map)
		return (0);
	copy = ft_tabdup(d.map.map);
	if (!copy)
		return (printf("Failed to duplicate the map for checking\n"), 0);
	if (!flood_check(d.map.map, d.player.y, d.player.x))
		return (ft_free_split(copy), 0);
	if (!check_map_wall(copy))
		return (ft_free_split(copy), 0);
	return (ft_free_split(copy), 1);
}
