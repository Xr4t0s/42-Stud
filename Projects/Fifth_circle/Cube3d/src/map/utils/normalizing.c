/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:52:08 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 22:23:19 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_normalization(t_normalize *tmp, t_data *d, int index)
{
	d->map.map[index] = NULL;
	establish_map_size(d);
	tmp->count = 0;
	tmp->copy = ft_calloc(8, d->map.height + 1);
	if (!tmp->copy)
		return (0);
	tmp->i = 0;
	if (!check_if_others_char(&d->map))
		return (0);
	return (1);
}

static int	init_loop(t_normalize *tmp, t_data *d)
{
	tmp->j = 0;
	tmp->copy[tmp->i] = malloc(sizeof(char) * (d->map.width + 1));
	if (!tmp->copy[tmp->i])
	{
		ft_free_split(tmp->copy);
		return (0);
	}
	return (1);
}

static int	loop(t_normalize *tmp, t_data *d)
{
	if (d->map.map[tmp->i][tmp->j] == ' ' || d->map.map[tmp->i][tmp->j] == '\t')
		tmp->copy[tmp->i][tmp->j] = '.';
	else
		tmp->copy[tmp->i][tmp->j] = d->map.map[tmp->i][tmp->j];
	if (d->map.map[tmp->i][tmp->j] == 'S' || d->map.map[tmp->i][tmp->j] == 'N'
		|| d->map.map[tmp->i][tmp->j] == 'E'
		|| d->map.map[tmp->i][tmp->j] == 'W')
	{
		tmp->count++;
		if (tmp->count > 1)
			return (tmp->copy[tmp->i + 1] = NULL, ft_free_split(tmp->copy), 0);
		d->player.x = tmp->j;
		d->player.xp = d->player.x * d->scale + 4;
		d->player.y = tmp->i;
		d->player.yp = d->player.y * d->scale + 4;
		if (d->map.map[tmp->i][tmp->j] == 'S')
			d->player.angle = 1.57;
		if (d->map.map[tmp->i][tmp->j] == 'E')
			d->player.angle = 0;
		if (d->map.map[tmp->i][tmp->j] == 'N')
			d->player.angle = 4.71;
		if (d->map.map[tmp->i][tmp->j] == 'W')
			d->player.angle = 3.14;
	}
	return (1);
}

int	normalize_map(t_data *d, int index)
{
	t_normalize	tmp;

	if (!init_normalization(&tmp, d, index))
		return (ft_free_split(tmp.copy), 0);
	while (d->map.map[tmp.i])
	{
		if (!init_loop(&tmp, d))
			return (0);
		while (d->map.map[tmp.i][tmp.j])
		{
			if (!loop(&tmp, d))
				return (0);
			tmp.j++;
		}
		while (tmp.j < d->map.width)
			tmp.copy[tmp.i][tmp.j++] = '.';
		tmp.copy[tmp.i][tmp.j] = 0;
		tmp.i++;
	}
	tmp.copy[tmp.i] = NULL;
	if (tmp.count == 0)
		return (ft_free_split(tmp.copy), 0);
	ft_free_split(d->map.map);
	d->map.map = tmp.copy;
	return (1);
}
