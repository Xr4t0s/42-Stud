/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/06 22:10:05 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	is_builtin(const char *cmd)
// {
// 	if (!cmd)
// 		return (0);
// 	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
// 		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
// 		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
// 		|| !ft_strcmp(cmd, "exit"));
// }

// int	exec_builtin(char **args)
// {
// 	if (!args || !args[0])
// 		return (0);
// 	if (!ft_strcmp(args[0], "echo"))
// 		return (echo(args));
// 	return (1);
// }

int	execute_commands(t_cmd *cmds, char **envp)
{
	t_cmd	*tmp;
	pid_t	pid;
	char	*joined;
	int		fd[2];
	int		status_code;
	int		i;

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
			joined = ft_strjoin("/usr/bin/", tmp->bin[i]);
			execve(joined, &tmp->bin[i], envp);
			perror("");
			free(joined);
			exit(127);
		}
		else
		{
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

