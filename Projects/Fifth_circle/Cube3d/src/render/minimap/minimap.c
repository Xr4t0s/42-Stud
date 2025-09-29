/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 22:46:34 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 23:35:03 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

static void	init_var(t_minivar *mini, char *addr, int bpp, int line_len)
{
	mini->addr = addr;
	mini->x = 0;
	mini->y = 0;
	mini->px = 0;
	mini->py = 0;
	mini->color = 0;
	mini->bpp = bpp;
	mini->line_len = line_len;
}

void	apply_color(t_minivar *mini, t_data *data)
{
	char	**map;

	map = data->map.map;
	mini->color = 0x000000;
	if (map[mini->y][mini->x] == '1')
		mini->color = 0x444444;
	else if (map[mini->y][mini->x] == '0'
		|| map[mini->y][mini->x] == 'N'
		|| map[mini->y][mini->x] == 'S'
		|| map[mini->y][mini->x] == 'E'
		|| map[mini->y][mini->x] == 'W'
		|| map[mini->y][mini->x] == '*')
		mini->color = 0xAAAAAA;
}

void	pre_draw(t_minivar *mini, t_data *data)
{
	while (mini->py < data->scale)
	{
		mini->px = 0;
		while (mini->px < data->scale)
		{
			minimap_draw_pixel(mini,
				mini->x * data->scale + mini->px,
				mini->y * data->scale + mini->py,
				data);
			mini->px++;
		}
		mini->py++;
	}
	mini->x++;
}

void	draw_player(t_minivar *mini, t_data *data)
{
	mini->py = 0;
	while (mini->py <= 3)
	{
		mini->px = 0;
		while (mini->px <= 3)
		{
			mini->color = 0xFF0000;
			minimap_draw_pixel(mini,
				data->player.xp + mini->px,
				data->player.yp + mini->py,
				data);
			mini->px++;
		}
		mini->py++;
	}
}

void	minimap(t_data *data, char *addr, int bpp, int line_len)
{
	t_minivar	*mini;
	char		**map;

	mini = &data->minivar;
	init_var(mini, addr, bpp, line_len);
	map = data->map.map;
	mini->y = 0;
	while (map[mini->y])
	{
		mini->x = 0;
		while (map[mini->y][mini->x])
		{
			apply_color(mini, data);
			mini->py = 0;
			pre_draw(mini, data);
		}
		mini->y++;
	}
	draw_player(mini, data);
}
