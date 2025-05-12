/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:33:13 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/12 04:25:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "exit"))
		return (1);
	else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "pwd"))
		return (2);
	return (0);
}

void	exec_void_builtin(char **arg, char **env)
{
	if (!arg || !arg[0])
		return ;
	if (!ft_strcmp(arg[0], "env"))
		ft_env(env);
	if (!ft_strcmp(arg[0], "echo"))
		echo(arg);
	if (!ft_strcmp(arg[0], "pwd"))
		ft_pwd(arg);
	return ;
}

char	**exec_env_builtin(char **args, char **env, t_data *data)
{
	if (!args || !args[0])
		return (0);
	if (!ft_strcmp(args[0], "cd"))
		return (ft_cd(args, env));
	else if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, env));
	else if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, env));
	if (!ft_strcmp(args[0], "exit"))
		ft_exit(data);
	return (env);
}

int	pipe_creation(t_cmd *cmd)
{
	int	pipe_fd[2];

	while (cmd && cmd->next)
	{
		if (cmd->pipe)
		{
			if (pipe(pipe_fd) == -1)
				return (perror("pipe"), 1);
			cmd->output_fd = pipe_fd[1];
			cmd->next->input_fd = pipe_fd[0];
		}
		cmd = cmd->next;
	}
	return (0);
}
