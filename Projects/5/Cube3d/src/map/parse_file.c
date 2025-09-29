/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:09:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 23:41:50 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_param_utils(t_data *d, char *trimed, char **param)
{
	if (!ft_strncmp(param[0], "NO", 2) && ft_strlen(param[0]) == 2
		&& check_img(trimed, d) && !d->map.textures.no.img)
		handle_no_so(d, trimed, 1);
	else if (!ft_strncmp(param[0], "SO", 2) && ft_strlen(param[0]) == 2
		&& check_img(trimed, d) && !d->map.textures.so.img)
		handle_no_so(d, trimed, 2);
	else if (!ft_strncmp(param[0], "WE", 2) && ft_strlen(param[0]) == 2
		&& check_img(trimed, d) && !d->map.textures.we.img)
		handle_we_ea(d, trimed, 1);
	else if (!ft_strncmp(param[0], "EA", 2) && ft_strlen(param[0]) == 2
		&& check_img(trimed, d) && !d->map.textures.ea.img)
		handle_we_ea(d, trimed, 2);
	else if (ft_strlen(param[0]) == 1
		&& (!ft_strncmp(param[0], "F", 1) || !ft_strncmp(param[0], "C", 1)))
	{
		if (!ft_strncmp(param[0], "C", 1) && d->map.textures.fc[0][0] != -1)
			ft_exit("Key not valid", d, 1, 1);
		if (!ft_strncmp(param[0], "F", 1) && d->map.textures.fc[1][0] != -1)
			ft_exit("Key not valid", d, 1, 1);
		fulfill_fc(param, d);
	}
	else
		ft_exit("Key not valid", d, 1, 1);
}

static void	parse_param(t_data *d, char *line)
{
	char	**param;
	char	*trimed;

	param = NULL;
	trimed = NULL;
	if (!line)
		return ;
	line = ft_rm_char(line, " \t\n");
	if (!line[0])
	{
		free(line);
		return ;
	}
	param = ft_split(line, ';');
	if (!param || param[2])
		return ;
	if (param[1])
		trimed = remove_spaces(param[1]);
	parse_param_utils(d, trimed, param);
	if (param)
		ft_free_split(param);
	if (trimed)
		free(trimed);
	if (line)
		free(line);
}

char	*parse_map(t_data *d, char *line, int *i)
{
	char	*trimed;

	trimed = ft_strtrim(line, "\n");
	if (trimed[0] != 0)
	{
		d->map.map[(*i)++] = ft_strdup(trimed);
	}
	free(trimed);
	free(line);
	line = get_next_line(d->map.fd_file);
	return (line);
}

static int	parse_file_init(t_parsing *tmp, t_data *d, char *filename)
{
	tmp->i = 0;
	tmp->trimed = NULL;
	d->map.fd_file = open(filename, O_RDONLY);
	if (d->map.fd_file == -1)
		return (free(d->map.map), d->map.map = NULL, 0);
	tmp->line = get_next_line(d->map.fd_file);
	if (!tmp->line)
		return (0);
	tmp->ft = &ft_strncmp;
	return (1);
}

int	parse_file(t_data *d, char *filename)
{
	t_parsing	t;

	if (!parse_file_init(&t, d, filename))
		return (0);
	while (t.line)
	{
		t.i = 0;
		while (t.line[t.i] == ' ' || t.line[t.i] == '\t')
			t.i++;
		if (!t.ft(&t.line[t.i], "1", 1) || !t.ft(&t.line[t.i], "0", 1))
			break ;
		parse_param(d, t.line);
		t.line = get_next_line(d->map.fd_file);
	}
	if (!loop_parse_file(&t, d))
		return (0);
	if (!normalize_map(d, t.i))
		ft_exit("Failed to parse map", d, 1, 0);
	return (free(t.line), 1);
}
