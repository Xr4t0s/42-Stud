/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:41:43 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/07 04:17:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

static int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**add_var(char *str, char **env)
{
	int	i;
	char	**new_env;

	i = 0;
	new_env = malloc(sizeof(char *) * (env_len(env) + 2));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	new_env[i + 1] = NULL;
	return (free_env(env), new_env);
	
}

int	check_var(char *str)
{
	int	i;

	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	i = 1;
	while(str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	if (str[i] == '=')
		return (i);
	return (0);
}

char	**ft_export(char **bin, char **env)
{
	int	i;
	int	index;
	char	*var;

	i = 0;
	while (bin[i])
	{
		index = check_var(bin[i]);
		if (!index)
		{
			i++;
			continue ;
		}
		var = ft_substr(bin[i], 0, index);
		env = duplicate_env(var, env);
		free(var);
		env = add_var(bin[i], env);
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
// 	env[0] = ft_strdup("ARG1='1234'");
// 	env[1] = ft_strdup("ARG3='12345'");
// 	env[2] = ft_strdup("ARG3=12346");
// 	env[3] = ft_strdup("ARG=4=12347");
// 	env[4] = NULL;

// 	tmp = env;
// 	env = ft_export(av, env);
// 	if (!env)
// 		env = tmp;
// 	int i;
// 	i = 0;
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
