/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:31:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/06 05:41:46 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Fonction pour check les perm avant douvrir les fichiers */
int	check_permissions(t_redir *redir, t_cmd **cmds)
{
	if (redir->type == R_IN)
	{
		if (access(redir->target, F_OK) == -1 || access(redir->target, R_OK) == -1)
		{
			if (redir->next)
				(*cmds)->bin[1] = ft_strdup(redir->target);
			return (-1);
		}
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

int	io_redirect(t_io *io, t_cmd **cmd)
{
	t_cmd	*tmp = *cmd;
	t_redir	*redir_tmp;
	int		i = 0;
	int		fd;

	redir_tmp = (*cmd)->redirection;
	while (tmp && tmp->redirection)
	{
		if (!check_permissions(tmp->redirection, cmd))
			return (0);
		if (check_permissions(tmp->redirection, cmd) == -1)
		{
			tmp->redirection = tmp->redirection->next;
			continue ;
		}
		if (i == io->index_in && tmp->exec)
		{
			if (tmp->redirection->type == R_IN)
			{
				// if (access(tmp->redirection->target, F_OK) == -1)
				// {
				// 	return (0);
				// }
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
		}
		else if (i == io->index_out)
		{
			if (tmp->redirection->type == R_OUT)
			{
				// if (access(tmp->redirection->target, F_OK) != -1)
				// {
				// 	if (access(tmp->redirection->target, W_OK) == -1)
				// 		tmp->exec = 0;
				// }
				(*cmd)->type = R_OUT;
				(*cmd)->output_fd = open(tmp->redirection->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			}
			else if (tmp->redirection->type == R_APPEND)
			{
				// if (access(tmp->redirection->target, F_OK) != -1)
				// {
				// 	if (access(tmp->redirection->target, W_OK & R_OK) == -1)
				// 		tmp->exec = 0;
				// }
				(*cmd)->type = R_APPEND;
				(*cmd)->output_fd = open(tmp->redirection->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
			}
		}
		else if (tmp->redirection->type == R_OUT || tmp->redirection->type == R_APPEND)
		{
			fd = open(tmp->redirection->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd != -1)
				close(fd);
		}
		tmp->redirection = tmp->redirection->next;
		i++;
	}
	(*cmd)->redirection = redir_tmp;
	return (1);
}
