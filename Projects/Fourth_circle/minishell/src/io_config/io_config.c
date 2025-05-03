// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   io_config.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/03 01:47:44 by nitadros          #+#    #+#             */
// /*   Updated: 2025/05/03 05:45:32 by nitadros         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// static void	init_io(t_io *io)
// {
// 	io->i = 0;
// 	io->index_in = 0;
// 	io->index_out = 0;
// }

// static void	io_loop(t_redir *tmp, t_io *io)
// {
// 	if (tmp->type == R_IN)
// 		io->index_in = io->i;
// 	else if (tmp->type == R_HEREDOC)
// 		io->index_in = io->i;
// 	else if (tmp->type == R_OUT)
// 		io->index_out = io->i;
// 	else if (tmp->type == R_APPEND)
// 		io->index_out = io->i;
// }

// int	io_config(t_cmd *cmds)
// {
// 	t_io	io;
// 	t_redir	*tmp;

// 	init_io(&io);
// 	if (!cmds)
// 		return (0);
// 	while (cmds)
// 	{
// 		if (!cmds->redirection)
// 		{
// 			cmds = cmds->next;
// 			continue;
// 		}
// 		io.i = 0;
// 		tmp = cmds->redirection;
// 		while (tmp)
// 		{
// 			io_loop(tmp, &io);
// 			tmp = tmp->next;
// 			io.i++;
// 		}
// 		io_redirect(&io, cmds);
// 		cmds = cmds->next;
// 	}
// 	return (1);
// }


// // int main(void)
// // {
// // 	t_cmd	*cmds;
// // 	cmds = NULL;
// // 	cmds = malloc(sizeof(t_cmd));
// // 	cmds->bin = malloc(sizeof(char *) * 3);
// // 	cmds->redirection = malloc(sizeof(t_redir *) * 5);
// // 	cmds->bin[0] = "echo";
// // 	cmds->bin[1] = "hello";
// // 	cmds->bin[2] = NULL;
// // 	cmds->input_fd = 0;
// // 	cmds->output_fd = 0;
// // 	cmds->pipe = 0;
// // 	cmds->next = NULL;
	
// // 	cmds->redirection->type = R_APPEND;
// // 	cmds->redirection->target = "target1";
// // 	cmds->redirection->next = malloc(sizeof(t_redir));

// // 	cmds->redirection->next->type = R_OUT;
// // 	cmds->redirection->next->target = "target2";
// // 	cmds->redirection->next->next = malloc(sizeof(t_redir));

// // 	cmds->redirection->next->next->type = R_APPEND;
// // 	cmds->redirection->next->next->target = "target3";
// // 	cmds->redirection->next->next->next = malloc(sizeof(t_redir));

// // 	cmds->redirection->next->next->next->type = R_HEREDOC;
// // 	cmds->redirection->next->next->next->target = "EOF";
// // 	cmds->redirection->next->next->next->next = malloc(sizeof(t_redir));

// // 	cmds->redirection->next->next->next->next->type = R_IN;
// // 	cmds->redirection->next->next->next->next->target = "input.txt";
// // 	cmds->redirection->next->next->next->next->next = NULL;

// // 	io_config(cmds);
// // 	// Free le tableau bin
// // 	free(cmds->bin);

// // 	// Free les redirections (liste chaînée)
// // 	t_redir *current = cmds->redirection;
// // 	t_redir *next;
// // 	while (current)
// // 	{
// // 		next = current->next;
// // 		free(current);
// // 		current = next;
// // 	}

// // 	// Free la structure cmds
// // 	free(cmds);

// // 	return (1);
// // }

