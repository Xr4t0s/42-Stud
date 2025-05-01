/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassembler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:45:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/01 16:36:54 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_redir(t_token_type token)
{
	return (token == T_R_IN || token == T_R_OUT
		|| token == T_HEREDOC || token == T_APPEND);
}

int	check_token_word(t_token_type token)
{
	return (token == T_WORD || token == T_QUOTE
		|| token == T_DQUOTE || token == T_VAR);
}

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
	new->redirection = NULL;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
		(*last)->next = new;
	*last = new;
	return (new);
}

void	parse_words(t_arg **arg, char **bin, int *i)
{
	while (*arg && check_token_word((*arg)->type))
	{
		bin[*i] = (*arg)->value;
		(*i)++;
		*arg = (*arg)->next;
	}
}

int	parse_redirection(t_arg **arg, t_redir **redir)
{
	t_redir_type	tmp;
	char			*target;

	if (!*arg || !check_token_redir((*arg)->type))
		return (0);
	if ((*arg)->type == T_R_OUT || (*arg)->type == T_APPEND)
		tmp = R_OUT;
	else
		tmp = R_IN;
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
	t_cmd			*cmd;
	t_cmd			*last_cmd;
	int				i;

	last_cmd = NULL;
	if (!data || !data->arg)
		return (1);
	data->cmd = NULL;
	while (data->arg)
	{
		cmd = append_new_cmd(&data->cmd, &last_cmd);
		if (!cmd)
			return (1);
		i = 0;
		while (data->arg && data->arg->type != T_PIPE)
		{
			parse_words(&data->arg, cmd->bin, &i);
			if (parse_redirection(&data->arg, &cmd->redirection))
				return (1);
		}
		if (data->arg && data->arg->type == T_PIPE)
			data->arg = data->arg->next;
	}
	return (0);
}
