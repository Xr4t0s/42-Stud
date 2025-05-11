/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 02:57:04 by nitadros         ###   ########.fr       */
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
	else if (!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "echo"))
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

int	execute_commands(t_data *data)
{
	t_cmd	*cmd = data->cmd;
	pid_t	pid;
	int		status_code = 0;

	// 1. Créer les pipes
	while (cmd && cmd->next)
	{
		if (cmd->pipe)
		{
			int pipe_fd[2];
			if (pipe(pipe_fd) == -1)
				return (perror("pipe"), 1);
			cmd->output_fd = pipe_fd[1];
			cmd->next->input_fd = pipe_fd[0];
		}
		cmd = cmd->next;
	}

	// 2. Exécuter chaque commande
	cmd = data->cmd;
	while (cmd)
	{
		if (!cmd->exec)
		{
			cmd = cmd->next;
			continue;
		}

		int is_env_builtin = (is_builtin(cmd->bin[0]) == 1);

		if (is_env_builtin)
		{
			int saved_in = dup(STDIN_FILENO);
			int saved_out = dup(STDOUT_FILENO);

			if (cmd->input_fd != -1)
			{
				dup2(cmd->input_fd, STDIN_FILENO);
				close(cmd->input_fd);
			}
			if (cmd->output_fd != -1)
			{
				dup2(cmd->output_fd, STDOUT_FILENO);
				close(cmd->output_fd);
			}
			data->envp = exec_env_builtin(cmd->bin, data->envp);

			dup2(saved_in, STDIN_FILENO);
			dup2(saved_out, STDOUT_FILENO);
			close(saved_in);
			close(saved_out);

			cmd = cmd->next;
			continue;
		}

		pid = fork();
		if (pid == -1)
			return (perror("fork"), 1);

		if (pid == 0) // Child
		{
			if (cmd->input_fd != -1)
			{
				dup2(cmd->input_fd, STDIN_FILENO);
				close(cmd->input_fd);
			}
			if (cmd->output_fd != -1)
			{
				dup2(cmd->output_fd, STDOUT_FILENO);
				close(cmd->output_fd);
			}

			// Fermer tous les autres fds des autres commandes
			t_cmd *c = data->cmd;
			while (c)
			{
				if (c != cmd)
				{
					if (c->input_fd > 2)
						close(c->input_fd);
					if (c->output_fd > 2)
						close(c->output_fd);
				}
				c = c->next;
			}

			if (is_builtin(cmd->bin[0]) == 2)
			{
				exec_void_builtin(cmd->bin, data->envp);
				exit(0);
			}

			int i = 0;
			while (cmd->bin[i] && !cmd->bin[i][0])
				i++;
			char *path = find_path(data->envp, cmd->bin[i]);
			if (!path)
			{
				perror("command not found");
				exit(127);
			}
			execve(path, &cmd->bin[i], data->envp);
			perror("execve failed");
			exit(127);
		}
		else // Parent
		{
			if (cmd->input_fd > 2)
				close(cmd->input_fd);
			if (cmd->output_fd > 2)
				close(cmd->output_fd);
		}
		cmd = cmd->next;
	}

	// 3. Wait
	cmd = data->cmd;
	while (cmd)
	{
		if (cmd->exec && is_builtin(cmd->bin[0]) != 1)
			wait(&status_code);
		cmd = cmd->next;
	}
	return (status_code);
}




