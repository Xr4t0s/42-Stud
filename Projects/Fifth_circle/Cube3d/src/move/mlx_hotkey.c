/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hotkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 23:17:57 by engiacom          #+#    #+#             */
/*   Updated: 2025/06/29 18:16:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "raycast.h"

int	go_up(t_data *data)
{
	if (data->map.map[(data->player.yP - 1) / 10][data->player.x] == '1')
		return (0);
	data->player.yP -= 1;
	data->player.y = data->player.yP / 10;
	return (1);
}

int	go_down(t_data *data)
{
	if (data->map.map[(data->player.yP + 4) / 10][data->player.x] == '1')
		return (0);
	data->player.yP += 1;
	data->player.y = data->player.yP / 10;
	return (1);
}

int	go_left(t_data *data)
{
	if (data->map.map[data->player.y][(data->player.xP - 1) / 10] == '1')
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
}

int	handle_keypress(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 13 || keycode == 65362 || keycode == 119)
		go_up(data);
	else if (keycode == 1 || keycode == 65364 || keycode == 115)
		go_down(data);
	else if (keycode == 0 || keycode == 65361 || keycode == 97)
		go_left(data);
	else if (keycode == 2 || keycode == 65363 || keycode == 100)
		go_right(data);
	else if (keycode == 65307)
		free_all(data, 1), exit(0);
	return (1);
}

int	movements(t_data *data)
{
	mlx_hook(data->mlx.win, 2, 1L << 0, handle_keypress, data);
	return (1);
}
