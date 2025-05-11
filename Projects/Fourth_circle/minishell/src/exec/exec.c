/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:34:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 08:27:20 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env_builtin(t_data **data, t_cmd **cmd)
{
	int	saved_in;
	int	saved_out;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	if ((*cmd)->input_fd != -1)
	{
		dup2((*cmd)->input_fd, STDIN_FILENO);
		close((*cmd)->input_fd);
	}
	if ((*cmd)->output_fd != -1)
	{
		dup2((*cmd)->output_fd, STDOUT_FILENO);
		close((*cmd)->output_fd);
	}
	(*data)->envp = exec_env_builtin((*cmd)->bin, (*data)->envp);
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
	return (1);
}

void	exec_child_process(t_cmd *cmd, t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	if (is_builtin(cmd->bin[0]) == 2)
	{
		exec_void_builtin(cmd->bin, data->envp);
		exit(0);
	}
	while (cmd->bin[i] && !cmd->bin[i][0])
		i++;
	path = find_path(data->envp, cmd->bin[i]);
	if (!path)
	{
		perror("command not found");
		exit(127);
	}
	printf("%s\n", path);
	execve(path, &cmd->bin[i], data->envp);
	perror("");
	exit(127);
}

void	init_child_process(t_cmd *cmd, t_data *data)
{
	t_cmd	*c;

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
	c = data->cmd;
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
	exec_child_process(cmd, data);
}

int	execute_loop(t_cmd *cmd, t_data *data, pid_t *pid)
{
	if (!cmd->exec)
		return (0);
	if (is_builtin(cmd->bin[0]) == 1)
	{
		init_env_builtin(&data, &cmd);
		return (0);
	}
	*pid = fork();
	if (*pid == -1)
		return (perror("fork"), 1);
	if (*pid == 0)
		init_child_process(cmd, data);
	else
	{
		if (cmd->input_fd > 2)
			close(cmd->input_fd);
		if (cmd->output_fd > 2)
			close(cmd->output_fd);
	}
	return (0);
}

int	execute_commands(t_data *data)
{
	t_cmd	*cmd;
	pid_t	pid;
	int		status_code;

	status_code = 0;
	cmd = data->cmd;
	pipe_creation(cmd);
	cmd = data->cmd;
	while (cmd)
	{
		if (execute_loop(cmd, data, &pid))
			return (1);
		cmd = cmd->next;
	}
	cmd = data->cmd;
	while (cmd)
	{
		if (cmd->exec && is_builtin(cmd->bin[0]) != 1)
			wait(&status_code);
		cmd = cmd->next;
	}
	return (status_code);
}
