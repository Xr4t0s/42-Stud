/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassembler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:45:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/03 18:08:25 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*append_new_cmd(t_cmd **head, t_cmd **last)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->bin = ft_calloc(64, sizeof(char *));
	if (!new->bin)
	{
		free(new);
		return (NULL);
	}
	new->pipe = 0;
	new->input_fd = -1;
	new->output_fd = -1;
	new->redirection = NULL;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		(*last)->next = new;
	*last = new;
	return (new);
}

void	parse_words(t_arg **arg, char **bin)
{
	int	i;

	i = 0;
	while (bin[i])
		i++;
	while (*arg && check_token_word((*arg)->type))
	{
		bin[i] = ft_strdup((*arg)->value);
		i++;
		*arg = (*arg)->next;
	}
	bin[i] = NULL;
}

int	parse_redirection(t_arg **arg, t_redir **redir)
{
	t_redir_type	tmp;
	char			*target;

	if (!*arg || !check_token_redir((*arg)->type))
		return (0);
	if ((*arg)->type == T_R_OUT)
		tmp = R_OUT;
	else if ((*arg)->type == T_APPEND)
		tmp = R_APPEND;
	else if ((*arg)->type == T_R_IN)
		tmp = R_IN;
	else if ((*arg)->type == T_HEREDOC)
		tmp = R_HEREDOC;
	*arg = (*arg)->next;
	if (!*arg)
		return (1);
	target = (*arg)->value;
	ft_lstadd_back_r(redir, ft_lstnew_r(tmp, target));
	*arg = (*arg)->next;
	return (0);
}

int	reassembler(t_data *data)
{
	t_cmd	*cmd;
	t_cmd	*last_cmd;
	t_arg	*arg;

	last_cmd = NULL;
	if (!data || !data->arg)
		return (1);
	data->cmd = NULL;
	arg = data->arg;
	while (arg)
	{
		cmd = append_new_cmd(&data->cmd, &last_cmd);
		if (!cmd)
			return (1);
		while (arg && arg->type != T_PIPE)
		{
			parse_words(&arg, cmd->bin);
			if (parse_redirection(&arg, &cmd->redirection))
				return (1);
		}
		reassembler_check(&arg, &cmd);
	}
	return (0);
}
