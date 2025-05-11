/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/12 00:32:12 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	**copy_env(char **envp)
{
	char	**env;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	t_data	*data;

	i = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	data = malloc(sizeof(t_data));
	data->envp = copy_env(env);
	(void)ac;
	(void)av;
	data->arg = NULL;
	data->cmd = NULL;
	data->last_code = 0;
	printf(RED "\n");
	printf("███╗   ███╗██╗███╗   ██╗██╗███████"
		"╗██╗  ██╗███████╗██╗     ██╗     \n");
	printf("████╗ ████║██║████╗  ██║██║██╔════"
		"╝██║  ██║██╔════╝██║     ██║     \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████"
		"╗███████║█████╗  ██║     ██║     \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██"
		"║██╔══██║██╔══╝  ██║     ██║     \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████"
		"║██║  ██║███████╗███████╗███████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════"
		"╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
	printf(RESET "\n");
	read_input(data);
	while (data->envp[i])
		free(data->envp[i++]);
	free(data->envp);
	ft_lstclear_m(&data->arg);
	ft_lstclear_c(&data->cmd);
	free(data);
	rl_clear_history();
}
