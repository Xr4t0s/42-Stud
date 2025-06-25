/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:04:33 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 00:33:11 by nitadros         ###   ########.fr       */
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

static void	establish_map_size(t_data *d)
{
	int		i;
	int		j;
	int		max_width;
	
	i = 0;
	j = 0;
	max_width = 0;
	while (d->map.map[i])
	{
		while (d->map.map[i][j])
			j++;
		if (j > max_width)
			max_width = j;
		j = 0;
		i++;
	}
	d->map.height = i;
	d->map.width = max_width;	
}

void	normalize_map(t_data *d)
{
	int		i;
	int		j;
	char	**copy;

	establish_map_size(d);
	copy = malloc(sizeof(char *) * (d->map.height + 1));
	if (!copy)
		return ;	
	i = 0;
	while (d->map.map[i])
	{
		j = 0;
		copy[i] = malloc(sizeof(char) * (d->map.width + 1));
		if (!copy[i])
		{
			ft_free_split(copy);
			return ;
		}
		while (d->map.map[i][j])
		{
			if (d->map.map[i][j] == ' ' || d->map.map[i][j] == '\t')
				copy[i][j] = '.';
			else
				copy[i][j] = d->map.map[i][j];
			if (d->map.map[i][j] == 'S' || d->map.map[i][j] == 'N' || d->map.map[i][j] == 'E' || d->map.map[i][j] == 'W')
			{
				d->player.x = j;
				d->player.y = i;
			}
			j++;
		}
		while (j < d->map.width)
			copy[i][j++] = '.';
		copy[i][j] = 0;
		i++;
	}
	copy[i] = NULL;
	ft_free_split(d->map.map);
	d->map.map = copy;
}

void	handle_no_so(t_data *d, char *trimed, int target)
{
	int fd = open(trimed, O_RDONLY);
	if (fd == -1)
		return ;
	close(fd);
	if (target == 1)
	{
		d->map.textures.no.img = mlx_xpm_file_to_image(
				d->mlx.mlx,
				trimed,
				&d->map.textures.no.width,
				&d->map.textures.no.height);
	}
	else
	{
		d->map.textures.so.img = mlx_xpm_file_to_image(
				d->mlx.mlx,
				trimed,
				&d->map.textures.so.width,
				&d->map.textures.so.height);
	}
}

void	handle_we_ea(t_data *d, char *trimed, int target)
{
	int fd = open(trimed, O_RDONLY);
	if (fd == -1)
		return ;
	close(fd);
	if (target == 1)
	{
		d->map.textures.we.img = mlx_xpm_file_to_image(
				d->mlx.mlx,
				trimed,
				&d->map.textures.we.width,
				&d->map.textures.we.height);
	}
	else
	{
		d->map.textures.ea.img = mlx_xpm_file_to_image(
				d->mlx.mlx,
				trimed,
				&d->map.textures.ea.width,
				&d->map.textures.ea.height);
	}
}
