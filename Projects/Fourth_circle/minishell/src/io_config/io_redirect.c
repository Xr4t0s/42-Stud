/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:31:57 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/04 03:28:07 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	io_redirect(t_io *io, t_cmd **cmd)
{
	t_redir	*tmp = (*cmd)->redirection;
	int		i = 0;
	int		fd;

	while (tmp)
	{
		if (i == io->index_in)
		{
			if (tmp->type == R_IN)
			{
				(*cmd)->input_fd = open(tmp->target, O_RDONLY);
				if ((*cmd)->input_fd == -1)
					return (0);	
			}
			else if (tmp->type == R_HEREDOC)
				(*cmd)->input_fd = heredoc(tmp);
		}
		else if (i == io->index_out)
		{
			if (tmp->type == R_OUT)
				(*cmd)->output_fd = open(tmp->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else if (tmp->type == R_APPEND)
				(*cmd)->output_fd = open(tmp->target, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else
		{
			fd = open(tmp->target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd != -1)
				close(fd);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}
