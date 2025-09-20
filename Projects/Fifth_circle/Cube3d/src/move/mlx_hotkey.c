/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hotkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 23:17:57 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/20 01:20:32 by nitadros         ###   ########.fr       */
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
		data->player.yP += sin(data->player.angle) * 1.5;
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 / 10] != '1' && data->map.map[(int)data->player.yP / 10][xP1 /10] != 'D')
	{
		data->player.xP += cos(data->player.angle) * 1.5;
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
		data->player.yP -= sin(data->player.angle) * 1.5;
		data->player.y = data->player.yP / 10;
	}
	if (data->map.map[(int)data->player.yP / 10][xP1 /10] != '1' && data->map.map[(int)data->player.yP / 10][xP1 /10] != 'D')
	{
		data->player.xP -= cos(data->player.angle) * 1.5;
		data->player.x = data->player.xP / 10;
	}
	return (1);
}	

int	go_left(t_data *data)
{
	data->player.angle -= data->player.rot;
	if (data->player.angle < 0)
		data->player.angle = 6.28;
	return (1);
}

int	go_right(t_data *data)
{
	data->player.angle += data->player.rot;
	if (data->player.angle > 6.28)
		data->player.angle = 0;
	return (1);
}

/* int	go_left(t_data *data)
{
	if (data->map.map[data->player.y][(data->player.xP - 1) / 10] == '1')
		return (0);
	if (data->map.map[(data->player.yP + 3) / 10][(data->player.xP - 1) / 10] == '1')
		return (0);
	data->player.xP -= 1;
	data->player.x = data->player.xP / 10;
	return (1);
}

int	go_right(t_data *data)
{
	int x_check = (data->player.xP + 4) / 10;
	int y1 = data->player.yP / 10;
	int y2 = (data->player.yP + 3) / 10;

	if (data->map.map[y1][x_check] == '1' || data->map.map[y2][x_check] == '1')
		return (0);
	data->player.xP += 1;
	data->player.x = data->player.xP / 10;
	return (0);
} */

int	handle_keypress(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		go_up(data);
	else if (keycode == 1 || keycode == 65364 || keycode == 115)
		go_down(data);
	else if (keycode == 0 || keycode == 65361 || keycode == 97)
		go_left(data);
	else if (keycode == 2 || keycode == 65363 || keycode == 100)
		go_right(data);
	else if (keycode == 101)
		data->raycast.door *= -1;
	else if (keycode == 65307)
		free_all(data, 1), exit(0);
	return (1);
}

int	movements(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 1L << 0, handle_keypress, data);
	return (1);
}
