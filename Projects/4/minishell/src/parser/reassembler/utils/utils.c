/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:51:05 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/02 03:07:38 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*ft_lstnew_r(t_redir_type type, char *target)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->target = ft_strdup(target);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_r(t_redir **arg, t_redir *new)
{
	t_redir	*tmp;

	if (*arg == NULL)
		*arg = new;
	else
	{
		tmp = *arg;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	reassembler_check(t_arg **arg, t_cmd **cmd)
{
	if (*arg && (*arg)->type == T_PIPE)
	{
		(*cmd)->pipe = 1;
		*arg = (*arg)->next;
	}
}

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
