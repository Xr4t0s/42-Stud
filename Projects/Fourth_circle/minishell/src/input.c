/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 05:32:34 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/12 04:55:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	print_data_cmds(t_data *data)
// {
// 	t_cmd	*cmd;
// 	int		i;
// 	int		n;

// 	if (!data || !data->cmd)
// 	{
// 		printf("Aucune commande.\n");
// 		return;
// 	}
// 	cmd = data->cmd;
// 	n = 1;
// 	while (cmd)
// 	{
// 		printf("== Commande %d ==\n", n++);
// 		i = 0;
// 		while (cmd->bin && cmd->bin[i])
// 		{
// 			printf("bin[%d] = %s\n", i, cmd->bin[i]);
// 			i++;
// 		}

// 		if (cmd->redirection)
// 		{
// 			t_redir *r = cmd->redirection;
// 			while (r)
// 			{
// 				const char *redir_str = r->type == R_IN ? "R_IN" :
// 										r->type == R_OUT ? "R_OUT" :
// 										r->type == R_APPEND ? "R_APPEND" :
// 										r->type == R_HEREDOC ? "R_HEREDOC" :
// 										"???";
// 				printf("Redirection : %s -> %s\n", redir_str, r->target);
// 				r = r->next;
// 			}
// 		}
// 		else
// 			printf("Aucune redirection.\n");
// 		if (cmd->pipe)
// 			printf("Piped !\n");
// 		printf("input : %d | output : %d\n", cmd->input_fd, cmd->output_fd);
// 		cmd = cmd->next;
// 	}
// }

// void    print(t_arg *arg)
// {
//     while (arg)
//     {
//         printf("%s\n", arg->value);
//         arg = arg->next;
//     }
// 	printf("\n");
// }

void	parse_and_execute(t_data *data, char *line)
{
	add_history(line);
	parser(line, &data->arg);
	if (!check_pipe(data->arg) && !check_redir_legit(data->arg))
	{
		expanser(&data->arg, data);
		slash(&data->arg);
		reassembler(data);
		if (io_config(data->cmd))
			data->last_code = execute_commands(data);
		else
			data->last_code = 1;
	}
}

int	read_input(t_data *data)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline(GREEN "minishell$" BLUE "-engiacom@nitadros-"
				GREEN ">>> " RESET);
		if (!line)
			break ;
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		if (!check_quote(line))
			parse_and_execute(data, line);
		free(line);
		ft_lstclear_m(&data->arg);
		ft_lstclear_c(&data->cmd);
	}
	ft_lstclear_m(&data->arg);
	ft_lstclear_c(&data->cmd);
	return (0);
}
