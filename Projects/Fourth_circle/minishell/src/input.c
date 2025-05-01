/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:45:35 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/01 16:37:55 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	read_input()
// {
// 	char *line;
// 	char **split_cmd;
	
// 	while (1)
// 	{
// 		line = readline("minishell> ");
// 		if (!line)
// 			break 	;
// 		if (*line != '\0')
// 			add_history(line);
		
// 		split_cmd = ft_split(line, ' ');
// 		if (is_builtin(split_cmd[0]))
// 			exec_builtin(split_cmd);
// 		else
// 			printf("Commande non prise en charge\n");
// 		free(split_cmd[0]);
// 		free(split_cmd[1]);
// 		free(split_cmd);
// 		free(line);
// 	}
// 	clear_history();
// 	return (0);
// }


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
// 										"???";
// 				printf("Redirection : %s -> %s\n", redir_str, r->target);
// 				r = r->next;
// 			}
// 		}
// 		else
// 			printf("Aucune redirection.\n");

// 		cmd = cmd->next;
// 	}
// }


void    print(t_arg *arg)
{
    while (arg)
    {
        printf("%s\n", arg->value);
        arg = arg->next;
    }
	printf("\n");
}
int    read_input(t_data *data)
{
    char    *line;
    int        i;

    i = 0;
    while (1)
    {
        line = readline("minishell$ ");
        if (!line)
            break;
        if (*line != '\0')
            add_history(line);
        if (!check_quote(line))
        {
            parser(line, &data->arg);
            if (!check_pipe(data->arg))
            {
                //print(data->arg);
				expanser(&data->arg);
				//print(data->arg);
                reassembler(data);
                //print_data_cmds(data);
                free(line);
            }
            else
                printf("rl_on_new_line\n");
            ft_lstclear_m(&data->arg);
        }
        else
                printf("rl_on_new_line\n");
    }
    return (0);
}
