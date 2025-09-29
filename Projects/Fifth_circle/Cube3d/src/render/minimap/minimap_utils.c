/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:24:56 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 21:29:25 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

void	minimap_draw_pixel(t_minivar *mini, int x, int y, t_data *data)
{
	char	*dst;

	if (x >= 0 && x < data->mlx.width && y >= 0 && y < data->mlx.height)
	{
		dst = mini->addr + (y * mini->line_len + x * (mini->bpp / 8));
		if (*(unsigned int *)dst != 0x00FFFF00)
			*(unsigned int *)dst = mini->color;
	}
}
