/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:41:44 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:17 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		data->move.w = 1;
	else if (keycode == 1 || keycode == 65364 || keycode == 115)
		data->move.s = 1;
	else if (keycode == 0 || keycode == 97)
		data->move.a = 1;
	else if (keycode == 2 || keycode == 100)
		data->move.d = 1;
	else if (keycode == 65363)
		data->move.r = 1;
	else if (keycode == 65361)
		data->move.l = 1;
	else if (keycode == 65505)
		data->player.move_speed = 3;
	else if (keycode == 101)
		data->raycast.door *= -1;
	else if (keycode == 65453 && data->player.fov >= 0.8)
		data->player.fov -= data->player.fov_rot;
	else if (keycode == 65451 && data->player.fov <= 2)
		data->player.fov += data->player.fov_rot;
	else if (keycode == 109)
		data->move.m *= -1;
	else if (keycode == 65307)
		return (free_all(data, 1), exit(0), 1);
	return (1);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		data->move.w = 0;
	else if (keycode == 1 || keycode == 65364 || keycode == 115)
		data->move.s = 0;
	else if (keycode == 0 || keycode == 97)
		data->move.a = 0;
	else if (keycode == 2 || keycode == 100)
		data->move.d = 0;
	else if (keycode == 65363)
		data->move.r = 0;
	else if (keycode == 65361)
		data->move.l = 0;
	else if (keycode == 65505)
		data->player.move_speed = 1.5;
	return (1);
}
