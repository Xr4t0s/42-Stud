// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   heredoc.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/05/02 07:03:24 by nitadros          #+#    #+#             */
// /*   Updated: 2025/05/02 08:33:20 by nitadros         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

int heredoc(t_cmd *cmds)
{
	t_cmd	*tmp_cmd;
	t_redir	*tmp_redir;
	char	*target;
	char	*line;
	char	*joined;

	tmp_cmd = cmds;
	target = NULL;
	line = "";
	joined = "";
	while (tmp_cmd)
	{
		tmp_redir = tmp_cmd->redirection;
		while (tmp_redir)
		{
			if (tmp_redir->type == R_HEREDOC)
			{
				target = tmp_redir->target;
				while(ft_strcmp(line, target) != 0)
				{
					line = readline("heredoc> ");
					joined = ft_strjoin(joined, line);
					joined = ft_strjoin(joined, "\n");
				}
				size_t len = ft_strlen(joined) - ft_strlen(target) - 1;
                joined[len - 1] = '\0';		
			}
			tmp_redir = tmp_redir->next;
		}
		tmp_cmd = tmp_cmd->next;
	}
	printf("%s\n", joined);
	free(joined);
}

// int main(void)
// {
//     // Allocation manuelle de la redirection
//     t_redir *redir = malloc(sizeof(t_redir));
//     if (!redir)
//         return 1;

//     redir->type = R_HEREDOC;
//     redir->target = "END";
//     redir->next = NULL;

//     // Commande simulée avec cette redirection
//     t_cmd *cmd = malloc(sizeof(t_cmd));
//     if (!cmd)
//         return 1;

//     cmd->bin = NULL;         // Pas besoin de commande réelle ici
//     cmd->redirection = redir;
//     cmd->next = NULL;

//     // Appel de ta fonction à tester
//     heredoc(cmd);

//     // Nettoyage
//     free(redir);
//     free(cmd);

//     return 0;
// }
