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

static int	*string_to_int(char *str, int size)
{
	int		i;
	char	*ptr;
	int		*coords;

	i = 0;
	ptr = str;
	if (!str || size <= 0)
		return (NULL);
	coords = malloc(sizeof(int) * size);
	if (!coords)
		return (NULL);
	while (i < size)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '\0')
			break ;
		coords[i] = ft_atoi(ptr);
		while (*ptr != ' ' && *ptr != '\0')
			ptr++;
		i++;
	}
	return (coords);
}

static char	*get_file_data(char *filename)
{
	char	*line;
	char	*buffer;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !filename)
		return (ft_printf("Error with fd or filename parsing_map.c:52"), NULL);
	buffer = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = tmp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	parse_map(char *filename, t_controller *multiplex)
{
	char	*tmp;
	char	*file_data;
	int		line_count;

	file_data = get_file_data(filename);
	if (!file_data)
		ft_return(NULL, 0, multiplex);
	line_count = count_lines(file_data);
	if (line_count == -1)
		ft_return(NULL, 0, multiplex);
	multiplex->map.y = line_count;
	tmp = delete_new_lines(file_data);
	if (!tmp)
		ft_return(NULL, 0, multiplex);
	file_data = tmp;
	multiplex->map.index = count_word(file_data, ' ');
	multiplex->map.x = multiplex->map.index / multiplex->map.y;
	if (multiplex->map.index <= 0)
		ft_return(NULL, 0, multiplex);
	multiplex->map.coords = string_to_int(file_data, multiplex->map.index);
	free(file_data);
	return ;
}
