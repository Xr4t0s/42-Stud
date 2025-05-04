/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/04 21:01:09 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**copy_env(char **envp)
{
	char	**env;
	int		i;

	i = 0;
	while(envp[i])
		i++;
	env = malloc(sizeof(char *) * i + 1);
	if (!env)
		return (NULL);
	i = 0;
	while(envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (env);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	**envp;

	envp = copy_env(env);
	(void)ac;
	(void)av;
	// data = malloc(sizeof(t_data));
	data.arg = NULL;
	data.cmd = NULL;
	data.last_code = 0;
	read_input(&data, envp);
	rl_clear_history();
}
