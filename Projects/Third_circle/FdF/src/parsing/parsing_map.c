/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:08:33 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/13 03:08:33 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map(char *xyz)
{
	int		i;
	t_map	*map;
	char	*str;
	char	**split;

	i = -1;
	if (!xyz)
		ft_return("No entries in map() function", 0);
	str = delete_new_lines(xyz);
	map = malloc(sizeof(t_map));
	if (!str || !map)
		ft_return("Error in map() function", 0);
	free(xyz);
	map->x = count_word(str, '\n');
	map->y = count_lines(str);
	map_init(&map);
	split = ft_split(str, ' ');
	if (!split)
		ft_return("Error while spliting (char *)map", 0);
	while(split[++i])
		map->coords[i] = ft_atoi(split[i]);
	free(split);
	free(str);
	return (map);
}

t_map	*parse_map(char *filename)
{
	int		fd;
	char	*buffer;
	char	*xyz;

	fd = open(filename, O_RDONLY);
	xyz = malloc(sizeof(char) * 400000);
	if (!xyz || fd < 0)
		return (0);
	buffer = get_next_line(fd);
	xyz = "";
	while(buffer)
	{
		xyz = ft_strjoin(xyz, buffer);
		if (!xyz)
		{
			free(buffer);
			free(xyz);
			ft_return("Error while parsing map", 0);
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (map(xyz));
}
