/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:33 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/24 08:59:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*remove_spaces(char *line)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	j = 0;
	clean = malloc(ft_strlen(line) + 1);
	while (line[i])
	{
		while (!ft_strncmp(&line[i], " ", 1) || !ft_strncmp(&line[i], "\n", 1))
			i++;
		if (!line[i])
			break ;
		clean[j++] = line[i++];
	}
	clean[j] = 0;
	return (clean);
}

void	handle_no(t_data *d, char *trimed)
{
	d->map.textures.no.img = mlx_xpm_file_to_image(
			d->mlx.mlx,
			trimed,
			&d->map.textures.no.width,
			&d->map.textures.no.height);
}

void	handle_so(t_data *d, char *trimed)
{
	d->map.textures.so.img = mlx_xpm_file_to_image(d->mlx.mlx,
			trimed,
			&d->map.textures.so.width,
			&d->map.textures.so.height);
}

void	handle_we(t_data *d, char *trimed)
{
	d->map.textures.we.img = mlx_xpm_file_to_image(d->mlx.mlx,
			trimed,
			&d->map.textures.we.width,
			&d->map.textures.we.height);
}

void	handle_ea(t_data *d, char *trimed)
{
	d->map.textures.ea.img = mlx_xpm_file_to_image(d->mlx.mlx,
			trimed,
			&d->map.textures.ea.width,
			&d->map.textures.ea.height);
}
