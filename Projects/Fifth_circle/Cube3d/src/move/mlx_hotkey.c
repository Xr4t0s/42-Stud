/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hotkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 23:17:57 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/22 15:24:55 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "raycast.h"


int check_angle(t_data *data)
{
	double x = data->player.xP;
	double y = data->player.yP;
	
	double angle = data->player.angle;
	if (angle >= 0 && angle <= 1.57)
	{
		if (data->map.map[(int)y / 10][(int)(x + 1) / 10] == '1' && data->map.map[(int)(y + 1) / 10][(int)x / 10] == '1')
			return (0);
	}
	else if (angle >= 1.57 && angle <= 3.14)
	{
		if (data->map.map[(int)y / 10][(int)(x - 1) / 10] == '1' && data->map.map[(int)(y + 1) / 10][(int)x / 10] == '1')
			return (0);
	}
	else if (angle >= 3.14 && angle <= 4.71)
	{
		if (data->map.map[(int)y / 10][(int)(x - 1) / 10] == '1' && data->map.map[(int)(y - 1) / 10][(int)x / 10] == '1')
			return (0);
	}
	else if (angle >= 4.71 && angle <= 6.28)
	{
		if (data->map.map[(int)y / 10][(int)(x + 1) / 10] == '1' && data->map.map[(int)(y - 1) / 10][(int)x / 10] == '1')
			return (0);
	}
	return (1);
}

int	go_up(t_data *data)
{
	double ny = sin(data->player.angle) * 3;
	int yP1 = data->player.yP + ny;
	double nx = cos(data->player.angle) * 3;
	int xP1 = data->player.xP + nx;
	if (!check_angle(data))
		return (0);
	if (data->map.map[yP1 / 10][(int)data->player.xP / 10] != '1' && data->map.map[yP1 / 10][(int)data->player.xP / 10] != 'D')
	{
		data->player.yP += sin(data->player.angle) * data->player.move_speed;
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 / 10] != '1' && data->map.map[(int)data->player.yP / 10][xP1 /10] != 'D')
	{
		data->player.xP += cos(data->player.angle) * data->player.move_speed;
		data->player.x = data->player.xP / 10;
	}
	return (1);
}

int	go_down(t_data *data)
{
	double ny = sin(data->player.angle) * 3;
	int yP1 = data->player.yP - ny;
	double nx = cos(data->player.angle) * 3;
	int xP1 = data->player.xP - nx;
	if (!check_angle(data))
		return (0);
	if (data->map.map[yP1 / 10][(int)data->player.xP / 10] != '1' && data->map.map[yP1 / 10][(int)data->player.xP / 10] != 'D')
	{
		data->player.yP -= sin(data->player.angle) * data->player.move_speed;
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 /10] != '1' && data->map.map[(int)data->player.yP / 10][xP1 /10] != 'D')
	{
		data->player.xP -= cos(data->player.angle) * data->player.move_speed;
		data->player.x = data->player.xP / 10;
	}
	return (1);
}	

int	go_left(t_data *data)
{
	double a = data->player.angle;
	/* vecteur strafe gauche = (sin(a), -cos(a)) */
	double ny = -cos(a) * 3.0;              // look-ahead 3 px
	int    yP1 = data->player.yP + ny;
	double nx =  sin(a) * 3.0;
	int    xP1 = data->player.xP + nx;

	if (!check_angle(data))
		return (0);

	/* slide sur Y puis sur X, comme go_up */
	if (data->map.map[yP1 / 10][(int)data->player.xP / 10] != '1'
	 && data->map.map[yP1 / 10][(int)data->player.xP / 10] != 'D')
	{
		data->player.yP += -cos(a) * (data->player.move_speed / 1.5);
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 / 10] != '1'
	 && data->map.map[(int)data->player.yP / 10][xP1 / 10] != 'D')
	{
		data->player.xP += sin(a) * (data->player.move_speed / 1.5);
		data->player.x = data->player.xP / 10;
	}
	return (1);
}

int	go_right(t_data *data)
{
	double a = data->player.angle;
	/* vecteur strafe gauche = (sin(a), -cos(a)) */
	double ny = cos(a) * 3.0;              // look-ahead 3 px
	int    yP1 = data->player.yP + ny;
	double nx =  -sin(a) * 3.0;
	int    xP1 = data->player.xP + nx;

	if (!check_angle(data))
		return (0);

	/* slide sur Y puis sur X, comme go_up */
	if (data->map.map[yP1 / 10][(int)data->player.xP / 10] != '1'
	 && data->map.map[yP1 / 10][(int)data->player.xP / 10] != 'D')
	{
		data->player.yP += cos(a) * (data->player.move_speed / 1.5);
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 / 10] != '1'
		&& data->map.map[(int)data->player.yP / 10][xP1 / 10] != 'D')
	{
		data->player.xP += -sin(a) * (data->player.move_speed / 1.5);
		data->player.x = data->player.xP / 10;
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
	// printf("%d\n", data->move.w);
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

int	movements(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 1L<<0, key_press, data);
	mlx_hook(data->mlx.win, 3, 1L<<1, key_release, data);
	return (1);
}
