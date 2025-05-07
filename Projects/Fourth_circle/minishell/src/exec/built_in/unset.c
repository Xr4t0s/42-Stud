/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:01:25 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/07 01:40:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
}

static int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static int	find_index(char *str, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (env[i])
	{
		if (!ft_strncmp(str, env[i], len) && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	**duplicate_env(char *str, char **env)
{
	int		i;
	int		k;
	int		index;
	char	**new_env;

	i = 0;
	k = 0;
	index = find_index(str, env);
	if (index == -1)
		return (env);
	new_env = malloc(sizeof(char *) * (env_len(env) + 1));
	while (env[i + k])
	{
		if (i == index)
			k++;
		if (env[i + k])
			new_env[i] = ft_strdup(env[i + k]);
		else
			break ;
		i++;
	}
	new_env[i] = NULL;
	free_env(env);
	return (free(env), new_env);
}

char	**ft_unset(char **bin, char **env)
{
	int	i;

	i = 0;
	while (bin[i])
	{
		env = duplicate_env(bin[i], env);
		i++;
	}
	return (env);
}

// int main(int ac, char **av)
// {
// 	char **env;
// 	char **tmp;
// 	(void)ac;
// 	av++;
// 	env = malloc(sizeof(char *) * 5);
// 	env[0] = ft_strdup("ARG1=1234");
// 	env[1] = ft_strdup("ARG3=12345");
// 	env[2] = ft_strdup("ARG3=12346");
// 	env[3] = ft_strdup("ARG=4=12347");
// 	env[4] = NULL;

// 	tmp = env;
// 	env = unset(av, env);
// 	if (!env)
// 		env = tmp;
// 	int i = 0;
// 	while(env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while(env[i])
// 	{
// 		free(env[i]);
// 		i++;
// 	}
// 	free(env);
// }
