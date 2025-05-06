/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:32:01 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/06 18:56:57 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(char *line)
{
	int		q;
	int		dq;
	int		i;

	q = 0;
	dq = 0;
	i = 0;
	while (line[i])
	{
		if (q == 0 && dq == 0 && line[i] == '\'')
			q = 1;
		else if (q == 0 && dq == 0 && line[i] == '\"')
			dq = 1;
		else if (line[i] == '\'' && q == 1)
			q = 0;
		else if (line[i] == '\"' && dq == 1)
			dq = 0;
		i++;
	}
	return (q + dq);
}

int	check_pipe(t_arg *arg)
{
	int	p;
	int	w;

	p = 0;
	w = 0;
	while (arg)
	{
		if (arg->type == T_WORD || arg->type == T_QUOTE
			|| arg->type == T_DQUOTE || arg->type == T_VAR
			|| check_token_redir(arg->type))
			w = 1;
		if (w == 1)
		{
			if ((check_token_redir(arg->type) || arg->type == T_PIPE) && p == 1)
				return (1);
			else if (arg->type == T_PIPE)
				p = 1;
			if ((!arg->next || !(arg->next->type == T_WORD
						|| arg->next->type == T_QUOTE
						|| arg->next->type == T_DQUOTE)) && p == 1)
				return (1);
			else
				p = 0;
			arg = arg->next;
		}
		else
			return (1);
	}
	return (p);
}

int	check_redir_legit(t_arg *arg)
{
	while (arg)
	{
		if (check_token_redir(arg->type))
		{
			if (!(arg->next) || !(check_token_word(arg->next->type)))
				return (1);
		}
		arg = arg->next;
	}
	return (0);
}

int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '|' || c == '<' || c == '>'
		|| c == '\'' || c == '\"' || c == '$');
}
