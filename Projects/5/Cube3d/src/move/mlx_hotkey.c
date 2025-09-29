/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hotkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 23:17:57 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:11 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

int	go_up(t_data *d)
{
	t_tmpvar	tmp;

	tmp.ny = sin(d->player.angle) * d->player.move_speed;
	tmp.yp1 = d->player.yp + tmp.ny;
	tmp.first = d->map.map[tmp.yp1 / d->scale][(int)d->player.xp / d->scale];
	if (!check_angle(d))
		return (0);
	if (tmp.first != '1' && tmp.first != 'D')
	{
		d->player.yp += sin(d->player.angle) * d->player.move_speed;
		d->player.y = d->player.yp / d->scale;
	}
	tmp.nx = cos(d->player.angle) * d->player.move_speed;
	tmp.xp1 = d->player.xp + tmp.nx;
	tmp.secnd = d->map.map[(int)d->player.yp / d->scale][tmp.xp1 / d->scale];
	if (tmp.secnd != '1' && tmp.secnd != 'D')
	{
		d->player.xp += cos(d->player.angle) * d->player.move_speed;
		d->player.x = d->player.xp / d->scale;
	}
	return (1);
}

int	go_down(t_data *d)
{
	t_tmpvar	tmp;

	tmp.ny = sin(d->player.angle) * d->player.move_speed;
	tmp.yp1 = d->player.yp - tmp.ny;
	tmp.first = d->map.map[tmp.yp1 / d->scale][(int)d->player.xp / d->scale];
	if (!check_angle(d))
		return (0);
	if (tmp.first != '1' && tmp.first != 'D')
	{
		d->player.yp -= sin(d->player.angle) * d->player.move_speed;
		d->player.y = d->player.yp / d->scale;
	}
	tmp.nx = cos(d->player.angle) * d->player.move_speed;
	tmp.xp1 = d->player.xp - tmp.nx;
	tmp.secnd = d->map.map[(int)d->player.yp / d->scale][tmp.xp1 / d->scale];
	if (tmp.secnd != '1' && tmp.secnd != 'D')
	{
		d->player.xp -= cos(d->player.angle) * d->player.move_speed;
		d->player.x = d->player.xp / d->scale;
	}
	return (1);
}

int	go_left(t_data *d)
{
	t_tmpvar	tmp;

	tmp.a = d->player.angle;
	tmp.ny = -cos(tmp.a) * (d->player.move_speed / 1.5);
	tmp.yp1 = d->player.yp + tmp.ny;
	tmp.first = d->map.map[tmp.yp1 / d->scale][(int)d->player.xp / d->scale];
	if (!check_angle(d))
		return (0);
	if (tmp.first != '1' && tmp.first != 'D')
	{
		d->player.yp += -cos(tmp.a) * (d->player.move_speed / 1.5);
		d->player.y = d->player.yp / d->scale;
	}
	tmp.nx = sin(tmp.a) * (d->player.move_speed / 1.5);
	tmp.xp1 = d->player.xp + tmp.nx;
	tmp.secnd = d->map.map[(int)d->player.yp / d->scale][tmp.xp1 / d->scale];
	if (tmp.secnd != '1' && tmp.secnd != 'D')
	{
		d->player.xp += sin(tmp.a) * (d->player.move_speed / 1.5);
		d->player.x = d->player.xp / d->scale;
	}
	return (1);
}

int	go_right(t_data *d)
{
	t_tmpvar	tmp;

	tmp.a = d->player.angle;
	tmp.ny = cos(tmp.a) * (d->player.move_speed / 1.5);
	tmp.yp1 = d->player.yp + tmp.ny;
	tmp.first = d->map.map[tmp.yp1 / d->scale][(int)d->player.xp / d->scale];
	if (!check_angle(d))
		return (0);
	if (tmp.first != '1' && tmp.first != 'D')
	{
		d->player.yp += cos(tmp.a) * (d->player.move_speed / 1.5);
		d->player.y = d->player.yp / d->scale;
	}
	tmp.nx = -sin(tmp.a) * (d->player.move_speed / 1.5);
	tmp.xp1 = d->player.xp + tmp.nx;
	tmp.secnd = d->map.map[(int)d->player.yp / d->scale][tmp.xp1 / d->scale];
	if (tmp.secnd != '1' && tmp.secnd != 'D')
	{
		d->player.xp += -sin(tmp.a) * (d->player.move_speed / 1.5);
		d->player.x = d->player.xp / d->scale;
	}
	return (1);
}

int	movements(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win, 3, 1L << 1, key_release, data);
	return (1);
}
