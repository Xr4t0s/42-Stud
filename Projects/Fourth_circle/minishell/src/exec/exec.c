/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/08 04:31:30 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "cd")
			|| !ft_strcmp(cmd, "unset"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
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
	return ;
}

char	**exec_env_builtin(char **args, char **env)
{
	if (!args || !args[0])
		return (0);
	if (!ft_strcmp(args[0], "cd"))
		return (ft_cd(args, env));
	else if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, env));
	else if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, env));
	// else if (!ft_strcmp(args[0], "exit"))
	// 	return (echo(args));
	return (env);
}

int	execute_commands(t_cmd *cmds, char ***envp)
{
	t_cmd	*tmp;
	pid_t	pid;
	char	*joined;
	int		fd[2];
	int		status_code;
	int		i;
	char **tmpenv = *envp;

	joined = NULL;
	tmp = cmds;
	while (tmp)
	{
		if (tmp->pipe && (tmp->type != R_APPEND && tmp->type != R_OUT))
		{
			if (!tmp->exec)
			{
				tmp = tmp->next;
				continue ;
			}
			if (pipe(fd) == -1)
				return (perror("pipe"), 1);
			tmp->output_fd = fd[1];
			if (tmp->next && tmp->next->input_fd == -1)
				tmp->next->input_fd = fd[0];
		}
		tmp = tmp->next;
	}
	tmp = cmds;
	while (tmp)
	{
		if (!tmp->exec)
		{
			tmp = tmp->next;
			continue ;
		}
		if (is_builtin(tmp->bin[0]) == 1)
		{
			*envp = exec_env_builtin(tmp->bin, *envp);
			tmp = tmp->next;
			continue ;
		}
		pid = fork();
		if (pid == -1)
			return (perror("fork"), 1);
		else if (pid == 0)
		{
			if (tmp->input_fd != -1 && tmp->input_fd != STDIN_FILENO)
			{
				dup2(tmp->input_fd, STDIN_FILENO);
				close(tmp->input_fd);
			}
			if (tmp->output_fd != -1 && tmp->output_fd != STDOUT_FILENO)
			{
				dup2(tmp->output_fd, STDOUT_FILENO);
				close(tmp->output_fd);
			}
			if (tmp->next && tmp->next->input_fd > 2)
				close(tmp->next->input_fd);
			i = 0;
			while (tmp->bin[i] && !tmp->bin[i][0])
				i++;
			joined = find_path(tmpenv, tmp->bin[i]);
			if (is_builtin(tmp->bin[0]))
			{
				free(joined);
				if (is_builtin(tmp->bin[0]) == 1)
					*envp = exec_env_builtin(tmp->bin, *envp);
				else if (is_builtin(tmp->bin[0]) == 2)
					exec_void_builtin(tmp->bin, *envp);
				exit(0);
			}
			else
			{
				execve(joined, &tmp->bin[i], *envp);
				free(joined);
				perror("Command not found");
				exit(127);
			}
		}
		else
		{
			free(joined);
			if (tmp->input_fd != -1 && tmp->input_fd != STDIN_FILENO)
				close(tmp->input_fd);
			if (tmp->output_fd != -1 && tmp->output_fd != STDOUT_FILENO)
				close(tmp->output_fd);
		}
		tmp = tmp->next;
	}
	
	tmp = cmds;
	while (tmp)
	{
		
		wait(&status_code);
		status_code = status_code % 127;
		tmp = tmp->next;
	}
	return (status_code);
}

