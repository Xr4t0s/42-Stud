/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:25:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/19 23:35:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**split_path(char **env)
{
	int		i;
	char	*path;
	char	**ret;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			path = env[i];
		i++;
	}
	path = ft_substr(path, 5, ft_strlen(path) - 5);
	ret = ft_split(path, ':');
	return (free(path), ret);
}

char	*read_path(char **path_dir, char *bin)
{
	t_tmp_path	tmp;

	tmp.i = -1;
	while (path_dir[++tmp.i])
	{
		tmp.dir = opendir(path_dir[tmp.i]);
		if (!tmp.dir)
			continue ;
		tmp.entry = readdir(tmp.dir);
		while (tmp.entry)
		{
			if (!ft_strncmp(tmp.entry->d_name, bin, ft_strlen(bin) + 1))
			{
				tmp.ret = ft_strjoin(path_dir[tmp.i], "/");
				tmp.tmp = ft_strjoin(tmp.ret, bin);
				return (closedir(tmp.dir), free(tmp.ret), tmp.tmp);
			}
			tmp.entry = readdir(tmp.dir);
		}
		closedir(tmp.dir);
	}
	return (NULL);
}

char	*read_current_dir(char *bin)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*tmp;
	char			*relative;
	int				i;

	i = 0;
	while (ft_strsrch(&bin[i], '/'))
		i++;
	relative = ft_substr(bin, 0, i - 1);
	tmp = ft_substr(bin, i, ft_strlen(bin) - i);
	dir = opendir(relative);
	if (!dir)
		return (free(tmp), free(relative), NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (!ft_strncmp(entry->d_name, tmp, ft_strlen(tmp)))
			return (closedir(dir), free(tmp), free(relative), bin);
		entry = readdir(dir);
	}
	closedir(dir);
	return (free(tmp), free(relative), NULL);
}

char	*find_path(char **env, char *bin)
{
	char	**path_dir;
	char	*path_file;

	path_dir = split_path(env);
	path_file = read_path(path_dir, bin);
	if (!path_file)
	{
		free_split(path_dir);
		free(path_file);
		path_file = read_current_dir(bin);
		if (!path_file)
			return (free(path_file), NULL);
		return (path_file);
	}
	return (free_split(path_dir), path_file);
}
