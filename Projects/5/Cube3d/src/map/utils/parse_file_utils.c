/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:56:16 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:52:50 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ascii(char *s)
{
	int	i;
	int	mark;

	mark = 1;
	i = 0;
	while (ft_isdigit(s[i]) || (!ft_strncmp(&s[i], ",", 1) && mark == 0))
	{
		mark = 0;
		if (!ft_strncmp(&s[i], ",", 1))
			mark = 1;
		i++;
	}
	if (s[i])
		return (0);
	return (1);
}

int	check_img(char *filename, t_data *d)
{
	void	*img;
	int		x;
	int		y;

	img = NULL;
	img = mlx_xpm_file_to_image(d->mlx.mlx, filename, &x, &y);
	if (!img)
		return (0);
	return (mlx_destroy_image(d->mlx.mlx, img), 1);
}

int	fulfill_fc(char **param, t_data *d)
{
	char	**fc;

	if (param[0] && ft_strlen(param[0]) != 1)
		return (0);
	if (!ft_strncmp(param[0], "C", 1) && check_ascii(param[1]))
	{
		fc = ft_split(param[1], ',');
		if (!fc || (!fc[0] || !fc[1] || !fc[2]))
			return (ft_free_split(fc), 0);
		d->map.textures.fc[0][0] = ft_atoi(fc[0]);
		d->map.textures.fc[0][1] = ft_atoi(fc[1]);
		d->map.textures.fc[0][2] = ft_atoi(fc[2]);
		ft_free_split(fc);
	}
	if (!ft_strncmp(param[0], "F", 1) && check_ascii(param[1]))
	{
		fc = ft_split(param[1], ',');
		if (!fc || (!fc[0] || !fc[1] || !fc[2]))
			return (ft_free_split(fc), 0);
		d->map.textures.fc[1][0] = ft_atoi(fc[0]);
		d->map.textures.fc[1][1] = ft_atoi(fc[1]);
		d->map.textures.fc[1][2] = ft_atoi(fc[2]);
		ft_free_split(fc);
	}
	return (1);
}

int	loop_parse_file(t_parsing *t, t_data *d)
{
	t->i = 0;
	while (t->line && ft_strncmp(t->line, "\n", 1))
		t->line = parse_map(d, t->line, &t->i);
	while (t->line)
	{
		t->line = parse_map(d, t->line, &t->i);
		if (t->line && ft_strncmp(t->line, "\n", 1))
			return (d->map.map[t->i] = NULL, free(t->line), 0);
	}
	return (1);
}
