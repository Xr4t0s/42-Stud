/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:52:48 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 02:04:53 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void	free_directions(t_data *d)
{
	if (d->map.textures.no.img)
		mlx_destroy_image((*d).mlx.mlx, (*d).map.textures.no.img);
	if (d->map.textures.so.img)
		mlx_destroy_image((*d).mlx.mlx, (*d).map.textures.so.img);
	if (d->map.textures.we.img)
		mlx_destroy_image((*d).mlx.mlx, (*d).map.textures.we.img);
	if (d->map.textures.ea.img)
		mlx_destroy_image((*d).mlx.mlx, (*d).map.textures.ea.img);
}

void	free_all(t_data *d)
{
	if (d->map.map)
		ft_free_split(d->map.map);
	free_directions(d);
//	mlx_destroy_display(d->mlx.mlx);
	free(d->mlx.mlx);
}
