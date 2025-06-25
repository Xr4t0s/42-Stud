/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 06:54:02 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/25 02:00:07 by nitadros         ###   ########.fr       */
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

static int	check_map(char **map)
{
	int	i;
	int	j;
	int	count_player;
	
	i = 0;
	j = 0;
	count_player = 0;
	while(map[i])
	{
		if (!check_if_map_closed(map, i))
			return (0);
		while(map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0')
			{
				if (map[i][j] == 'N' || map[i][j] == 'S'
					|| map[i][j] == 'W' || map[i][j] == 'E')
					count_player++;
				else
					return (0);
			}
			if (count_player > 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_map_data(t_map map)
{
	if (!check_map(map.map))
		return (0);
	return (1);
}
