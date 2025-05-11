/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:31:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 05:08:28 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_permissions(t_redir *redir, t_cmd **cmds)
{
	if (redir->type == R_IN)
	{
		if (access(redir->target, F_OK) == -1
			|| access(redir->target, R_OK) == -1)
			return (0);
	}
	else if (redir->type == R_OUT || redir->type == R_APPEND)
	{
		if (access(redir->target, F_OK) != -1)
		{
			if (access(redir->target, W_OK | R_OK) == -1)
			{
				(*cmds)->exec = 0;
				return (0);
			}
		}
	}
	return (1);
}

int	r_in(t_cmd **cmd, t_cmd *tmp)
{
	if (tmp->redirection->type == R_IN)
	{
		(*cmd)->input_fd = open(tmp->redirection->target, O_RDONLY);
		(*cmd)->type = R_IN;
		if ((*cmd)->input_fd == -1)
			return (0);
	}
	else if (tmp->redirection->type == R_HEREDOC)
	{
		(*cmd)->type = R_HEREDOC;
		(*cmd)->input_fd = heredoc(tmp->redirection);
	}
	return (1);
}

void	r_out(t_cmd **cmd, t_cmd *tmp)
{
	if (tmp->redirection->type == R_OUT)
	{
		(*cmd)->type = R_OUT;
		(*cmd)->output_fd = open(tmp->redirection->target,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (tmp->redirection->type == R_APPEND)
	{
		(*cmd)->type = R_APPEND;
		(*cmd)->output_fd = open(tmp->redirection->target,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
}

void	open_and_close(t_cmd *tmp)
{
	int	fd;

	if (tmp->redirection->type == R_OUT
		|| tmp->redirection->type == R_APPEND)
	{
		fd = open(tmp->redirection->target,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd != -1)
			close(fd);
	}
}

int	io_redirect(t_io *io, t_cmd **cmd)
{
	t_cmd	*tmp;
	t_redir	*redir_tmp;
	int		i;

	i = 0;
	tmp = *cmd;
	redir_tmp = (*cmd)->redirection;
	while (tmp && tmp->redirection)
	{
		if (!check_permissions(tmp->redirection, cmd))
			return (0);
		if (i == io->index_in && tmp->exec)
		{
			if (!r_in(cmd, tmp))
				return (0);
		}
		else if (i == io->index_out)
			r_out(cmd, tmp);
		else
			open_and_close(tmp);
		tmp->redirection = tmp->redirection->next;
		i++;
	}
	(*cmd)->redirection = redir_tmp;
	return (1);
}
