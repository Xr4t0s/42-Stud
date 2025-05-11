/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:25:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 23:46:35 by nitadros         ###   ########.fr       */
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
	int				i;
	DIR				*dir;
	struct dirent	*entry;
	char			*ret;

	i = -1;
	while (path_dir[++i])
	{
		dir = opendir(path_dir[i]);
		if (!dir)
			continue ;
		entry = readdir(dir);
		while (entry)
		{
			if (!ft_strncmp(entry->d_name, bin, ft_strlen(bin) + 1))
			{
				ret = ft_strjoin(path_dir[i], "/");
				ret = ft_strjoin(ret, bin);
				return (closedir(dir), ret);
			}
			entry = readdir(dir);
		}
		closedir(dir);
	}
	return (NULL);
}

char	*read_current_dir(char *bin)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*tmp;

	tmp = ft_substr(bin, 2, ft_strlen(bin) - 2);
	dir = opendir(".");
	if (!dir)
		return (free(tmp), NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (!ft_strncmp(entry->d_name, tmp, ft_strlen(tmp)))
			return (closedir(dir), free(tmp), bin);
		entry = readdir(dir);
	}
	closedir(dir);
	return (free(tmp), NULL);
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
