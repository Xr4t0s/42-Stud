/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkey_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:02:45 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:09 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_angle_data(t_tmp_angle *tmp, t_data *data)
{
	tmp->x = data->player.xp;
	tmp->y = data->player.yp;
	tmp->angle = data->player.angle;
	tmp->xtestpos = data->map.map[(int)tmp->y / data->scale]
	[(int)(tmp->x + 1) / data->scale];
	tmp->xtestneg = data->map.map[(int)tmp->y / data->scale]
	[(int)(tmp->x - 1) / data->scale];
	tmp->ytestpos = data->map.map[(int)(tmp->y + 1) / data->scale]
	[(int)tmp->x / data->scale];
	tmp->ytestneg = data->map.map[(int)(tmp->y - 1) / data->scale]
	[(int)tmp->x / data->scale];
}

int	check_angle(t_data *data)
{
	t_tmp_angle	tmp;

	init_angle_data(&tmp, data);
	if (tmp.angle >= 0 && tmp.angle <= 1.57)
	{
		if (tmp.xtestpos == '1' && tmp.ytestpos == '1')
			return (0);
	}
	else if (tmp.angle >= 1.57 && tmp.angle <= 3.14)
	{
		if (tmp.xtestneg == '1' && tmp.ytestpos == '1')
			return (0);
	}
	else if (tmp.angle >= 3.14 && tmp.angle <= 4.71)
	{
		if (tmp.xtestneg == '1' && tmp.ytestneg == '1')
			return (0);
	}
	else if (tmp.angle >= 4.71 && tmp.angle <= 6.28)
	{
		if (tmp.xtestpos == '1' && tmp.ytestneg == '1')
			return (0);
	}
	return (1);
}

int	view_left(t_data *data)
{
	data->player.angle -= data->player.rot;
	if (data->player.angle < 0)
		data->player.angle = 6.28;
	return (1);
}

int	view_right(t_data *data)
{
	data->player.angle += data->player.rot;
	if (data->player.angle > 6.28)
		data->player.angle = 0;
	return (1);
}

int	handle_keypress(int keycode, t_data *data)
{
	(void)keycode;
	if (data->move.w == 1)
		go_up(data);
	if (data->move.s == 1)
		go_down(data);
	if (data->move.a == 1)
		go_left(data);
	if (data->move.d == 1)
		go_right(data);
	if (data->move.r == 1)
		view_right(data);
	if (data->move.l == 1)
		view_left(data);
	return (1);
}
