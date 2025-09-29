/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:50:56 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 22:39:47 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_xpm(t_data *d)
{
	return (d->map.textures.ea.addr
		&& d->map.textures.so.addr
		&& d->map.textures.we.addr
		&& d->map.textures.no.addr);
}

int	check_data(t_data *d, char *filename)
{
	if (!parse_file(d, filename))
		ft_exit("Failed to parse file", d, 1, 0);
	if (!check_xpm(d))
		ft_exit("Failed to parse xpm", d, 1, 0);
	if (!check_map_data(*d) ||!check_param(*d))
		ft_exit("Failed to parse map", d, 1, 0);
	return (1);
}
