/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:03:24 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/03 08:10:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_heredoc(t_heredoc *init)
{
	init->index = 0;
	init->target = NULL;
	init->line = calloc(sizeof(char), 1);
	init->joined = calloc(sizeof(char), 1);
	init->tmp = NULL;
}

static void	heredoc_loop(t_redir **tmp_redir, t_heredoc *hrdc)
{
	size_t	len;

	(*hrdc).target = (*tmp_redir)->target;
	while (ft_strcmp((*hrdc).line, (*hrdc).target) != 0)
	{
		if ((*hrdc).line)
			free((*hrdc).line);
		(*hrdc).line = readline("heredoc> ");
		if (!(*hrdc).line)
			break ;
		(*hrdc).tmp = (*hrdc).joined;
		(*hrdc).joined = ft_strjoin((*hrdc).joined, (*hrdc).line);
		free((*hrdc).tmp);
		(*hrdc).tmp = (*hrdc).joined;
		(*hrdc).joined = ft_strjoin((*hrdc).joined, "\n");
		free((*hrdc).tmp);
	}
	free((*hrdc).line);
	len = ft_strlen((*hrdc).joined) - ft_strlen((*hrdc).target) - 1;
	(*hrdc).joined[len - 1] = '\0';
}

int	save_heredoc(t_heredoc hrdc)
{
	char	*index_str;
	char	*filename;
	int		fd;

	index_str = ft_itoa(hrdc.index);
	if (!index_str)
		return (perror("itoa"), 0);
	filename = malloc(strlen("/tmp/.heredoc_tmp_") + strlen(index_str) + 1);
	if (!filename)
		return (free(filename), perror("save heredoc"), 0);
	ft_strlcpy(filename, "/tmp/.heredoc_tmp_", 80);
	ft_strlcat(filename, index_str, 80);
	free(index_str);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (perror("save heredoc open"), free(filename), 0);
	if (write(fd, hrdc.joined, strlen(hrdc.joined)) == -1)
	{
		free(filename);
		return (perror("write"), close(fd), -1);
	}
	return (free(filename), fd);
}

int	heredoc(t_redir *redir)
{
	t_redir		*tmp_redir;
	t_heredoc	hrdc;

	init_heredoc(&hrdc);
	tmp_redir = redir;
	while (tmp_redir)
	{
		if (tmp_redir->type == R_HEREDOC)
		{
			heredoc_loop(&tmp_redir, &hrdc);
			hrdc.fd = save_heredoc(hrdc);
			if (!hrdc.fd)
				return (perror("heredoc"), 0);
			hrdc.index++;
		}
		tmp_redir = tmp_redir->next;
	}
	free(hrdc.joined);
	return (hrdc.fd);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	t_redir *redir = malloc(sizeof(t_redir));
// 	if (!redir)
// 		return (1);
// 	redir->type = R_HEREDOC;
// 	redir->target = "END";
// 	redir->next = NULL;

// 	t_cmd *cmd = malloc(sizeof(t_cmd));
// 	if (!cmd)
// 		return (free(redir), 1);
// 	cmd->bin = NULL;
// 	cmd->redirection = redir;
// 	cmd->next = NULL;

// 	if (!heredoc(cmd))
// 	{
// 		fprintf(stderr, "Heredoc failed\n");
// 		free(redir);
// 		free(cmd);
// 		return (1);
// 	}

// 	// Simulation d'ouverture et lecture du fichier temporaire
// 	char tmpfile[256];
// 	sprintf(tmpfile, "/tmp/.heredoc_tmp_0");
// 	int fd = open(tmpfile, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open tmpfile");
// 		free(redir);
// 		free(cmd);
// 		return (1);
// 	}

// 	printf("\n📄 Contenu lu depuis le fichier temporaire :\n");
// 	char buffer[1024];
// 	ssize_t n;
// 	while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[n] = '\0';
// 		printf("%s", buffer);
// 	}
// 	close(fd);

// 	// Supprimer le fichier temporaire après usage
// 	unlink(tmpfile);

// 	// Nettoyage
// 	free(redir);
// 	free(cmd);
// 	return (0);
// }
