/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:45:35 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/30 04:47:44 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_input()
{
	char *line;
	char **split_cmd;
	
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break 	;
		if (*line != '\0')
			add_history(line);
		
		split_cmd = ft_split(line, ' ');
		if (is_builtin(split_cmd[0]))
			exec_builtin(split_cmd);
		else
			printf("Commande non prise en charge\n");
		free(split_cmd[0]);
		free(split_cmd[1]);
		free(split_cmd);
		free(line);
	}
	clear_history();
	return (0);
}
