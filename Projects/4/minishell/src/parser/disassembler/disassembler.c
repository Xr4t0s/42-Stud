/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:57:12 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/11 04:24:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_var_qmark(t_parse *parse, t_arg **arg)
{
	int	k;

	k = 1;
	if (parse->s[parse->i + k] && parse->s[parse->i + k] == '?')
	{
		k++;
		append_arg(parse, k, arg, T_VAR);
	}
	return (k);
}

int	token_var_word(t_parse *parse, t_arg **arg)
{
	int		k;

	k = 1;
	if (parse->s[parse->i] && parse->s[parse->i] == '$')
	{
		if (parse->s[parse->i + k] && parse->s[parse->i + k] == '?')
			return (token_var_qmark(parse, arg));
		else if (parse->s[parse->i + k] && (ft_isalpha(parse->s[parse->i + k])
				|| parse->s[parse->i + k] == '_'))
		{
			k++;
			while (parse->s[parse->i + k] && (ft_isalnum(parse->s[parse->i + k])
					|| parse->s[parse->i + k] == '_'))
				k++;
			append_arg(parse, k, arg, T_VAR);
		}
		else
			return (token_word(parse, arg, 1));
		return (k);
	}
	return (0);
}

int	token_quote(t_parse *parse, t_arg **arg)
{
	int		k;

	k = 0;
	if (parse->s[parse->i] && parse->s[parse->i] == '\"')
	{
		k = 1;
		while (parse->s[parse->i + k] && parse->s[parse->i + k] != '\"')
		{
			k++;
		}
		k++;
		append_arg(parse, k, arg, T_DQUOTE);
		return (k);
	}
	return (k);
}

int	token_other(t_parse *parse, t_arg **arg)
{
	int		k;

	k = 0;
	if (parse->s[parse->i] && parse->s[parse->i] == ' ')
	{
		return (1);
	}
	else if (parse->s[parse->i] && parse->s[parse->i] == '|')
	{
		ft_lstadd_back_m(arg, ft_lstnew_m(T_PIPE, "|"));
		return (1);
	}
	else if (parse->s[parse->i] && parse->s[parse->i] == '\'')
	{
		k++;
		while (parse->s[parse->i + k] && parse->s[parse->i + k] != '\'')
			k++;
		k++;
		append_arg(parse, k, arg, T_QUOTE);
		return (k);
	}
	return (0);
}

int	parser(char *line, t_arg **arg)
{
	t_parse	parse;

	parse.s = line;
	init_parse(&parse);
	parse.i += check_cmd(&parse, arg);
	while (line[parse.i])
	{
		parse.i += token_r_left(&parse, arg);
		parse.i += token_r_right(&parse, arg);
		parse.i += token_other(&parse, arg);
		parse.i += check_cmd(&parse, arg);
		parse.i += token_var_word(&parse, arg);
		parse.i += token_quote(&parse, arg);
	}
	return (0);
}
