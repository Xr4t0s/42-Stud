/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:55:02 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/20 01:53:04 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	check_floor_and_ceiling(int	fc[2][3])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < 2)
	{
		while (j < 3)
		{
			if (fc[i][j] < 0 || fc[i][j] > 255)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	check_directions(t_direction direction)
{
	if (!direction.img)
		return (0);
	return (1);
}

static int check_Xtext_and_redir(t_textures textures)
{
	if (!check_directions(textures.no)
		|| !check_directions(textures.so)
		|| !check_directions(textures.we)
		|| !check_directions(textures.ea))
		return (0);
	if (!check_floor_and_ceiling(textures.fc))
		return (0);
	return (1);
}

int	check_param(t_data d)
{
	if (!check_Xtext_and_redir(d.map.textures))
		return (0);
	return (1);
}
