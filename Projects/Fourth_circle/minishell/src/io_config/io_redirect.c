/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:31:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/03 06:02:10 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	io_redirect(t_io *io, t_cmd *cmd)
{
	int		i;

	i = 0;
	while(cmd->redirection)
	{
		if (i == io->index_in)
		{
			if (cmd->redirection->type == R_IN)
				cmd->input_fd = open(cmd->redirection->target, O_RDONLY);
			else if (cmd->redirection->type == R_HEREDOC)
			{
				// creer ehredoc
				cmd->input_fd = open(cmd->redirection->target, O_RDONLY);
				// supprimer R_HEREDOC
			}
		}
		else if (i == io->index_out)
		{
			if (cmd->redirection->type == R_OUT)
				cmd->input_fd = open(cmd->redirection->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else if (cmd->redirection->type == R_APPEND)
				cmd->input_fd = open(cmd->redirection->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else
		{
			cmd->input_fd = open(cmd->redirection->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			close(cmd->input_fd);
		}
	}
}
