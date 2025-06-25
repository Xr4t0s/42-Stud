/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 06:54:02 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/25 07:08:52 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// int	check_directions(t_direction direction)
// {
	
// }

// int check_textures(t_textures textures)
// {
	
// }

static int	check_if_map_closed(char **map, int i)
{
	int	j;

	j = 0;
	if (i == 0 || map[i + 1] == NULL)
	{
		while(map[i][j])
		{
			if (map[i][j] != '1')
				return (0);
			j++;
		}
	}
	else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		return (0);
	return (1);
}

int	flood_check(char **map, int i, int j)
{
	if (i < 0 || j < 0 || map[i] == NULL || map[i][j] == '\0')
		return (0);  // fuite : hors limites ou ligne trop courte

	if (map[i][j] == '.' || map[i][j] == ' ')  // case vide anormale
		return (0);

	if (map[i][j] == '1' || map[i][j] == '*')  // mur ou déjà visité
		return (1);

	map[i][j] = '*';  // marquer comme visité

	return (
		flood_check(map, i + 1, j) &&
		flood_check(map, i - 1, j) &&
		flood_check(map, i, j + 1) &&
		flood_check(map, i, j - 1)
	);
}

int	check_map_data(t_data d)
{
	if (!flood_check(d.map.map, d.player.y, d.player.x))
		return (0);
	return (1);
}
