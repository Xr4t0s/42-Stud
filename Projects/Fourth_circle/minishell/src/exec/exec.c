/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/03 23:14:48 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(const char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

int	exec_builtin(char **args)
{
	if (!args || !args[0])
		return (0);
	if (!ft_strcmp(args[0], "echo"))
		return (echo(args));
	return (1);
}

int	execute_commands(t_cmd *cmds, char **envp)
{
	t_cmd	*tmp;
	pid_t	pid;
	char	*joined;
	int		saved_stdout;
	int		saved_stdin;
	char *argv[3];

	argv[0] = "ls";     // ou tout autre nom de commande
	argv[1] = "-la";
	argv[2] = NULL;
	tmp = cmds;
	joined = NULL;
	while(tmp)
	{
		saved_stdin = dup(STDIN_FILENO);
		saved_stdout = dup(STDOUT_FILENO);
		if (saved_stdout == -1 || saved_stdin == -1)
			return (perror("dup"), 0);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), 0);
		else if (pid == 0)
		{
			if (tmp->input_fd != -1)
			{
				if (dup2(tmp->input_fd, STDIN_FILENO) == -1)
					return (perror("dup2_IN"), 0);
				close(tmp->input_fd);
			}
			if (tmp->output_fd != -1)
			{
				if (dup2(tmp->output_fd, STDOUT_FILENO) == -1)
					return (perror("dup2_OUT"), 0);
				close(tmp->output_fd);
			}
			if (!envp)
				printf("ENVP NULL\n");
			joined = ft_strjoin("/usr/bin/", tmp->bin[0]);
			execve(joined, tmp->bin, envp);
			perror("execve");
			free(joined);
			return (0);
		}
		else
		{
			wait(NULL);
			free(joined);

			if (dup2(saved_stdin, STDIN_FILENO) == -1)
				return (perror("dup2 restore stdin"), 0);
			if (dup2(saved_stdout, STDOUT_FILENO) == -1)
				return (perror("dup2 restore stdout"), 0);

			close(saved_stdin);
			close(saved_stdout);

			if (tmp->input_fd != -1)
				close(tmp->input_fd);  // si besoin, dépend du contexte heredoc
			if (tmp->output_fd != -1)
				close(tmp->output_fd); // idem
		}
		tmp = tmp->next;
	}
	return (1);
}
