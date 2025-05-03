/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:57:12 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/04 00:39:32 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_var_qmark(char *c, int i, t_arg **arg)
{
	int		k;

	k = 1;
	if (c[i + k] && c[i + k] == '?')
	{
		k++;
		append_arg(c, i, k, arg, T_VAR);
	}
	return (k);
}

int	token_var_word(char *c, int i, t_arg **arg)
{
	int		k;

	k = 1;
	if (c[i] && c[i] == '$')
	{
		if (c[i + k] && c[i + k] == '?')
			return (token_var_qmark(c, i, arg));
		else if (c[i + k] && (ft_isalpha(c[i + k]) || c[i + k] == '_'))
		{
			k++;
			while (c[i + k] && (ft_isalnum(c[i + k]) || c[i + k] == '_'))
				k++;
			append_arg(c, i, k, arg, T_VAR);
		}
		else
			return (token_word(c, i, arg, 1));
		return (k);
	}
	return (0);
}

int	token_quote(char *c, int i, t_arg **arg)
{
	int		k;

	k = 0;
	if (c[i] && c[i] == '\"')
	{
		k = 1;
		while (c[i + k] && c[i + k] != '\"')
		{
			k++;
		}
		k++;
		append_arg(c, i + 1, k - 1, arg, T_DQUOTE);
		return (k);
	}
	return (k);
}

int	token_other(char *c, int i, t_arg **arg)
{
	int		k;

	k = 0;
	if (c[i] && c[i] == ' ')
	{
		return (1);
	}
	else if (c[i] && c[i] == '|')
	{
		ft_lstadd_back_m(arg, ft_lstnew_m(T_PIPE, "|"));
		return (1);
	}
	else if (c[i] && c[i] == '\'')
	{
		k++;
		while (c[i + k] && c[i + k] != '\'')
			k++;
		k++;
		append_arg(c, i + 1, k - 1, arg, T_QUOTE);
		return (k);
	}
	return (0);
}

int	parser(char *line, t_arg **arg)
{
	int	i;

	i = 0;
	i += check_cmd(line, arg);
	while (line[i])
	{
		i += token_r_left(line, i, arg);
		i += token_r_right(line, i, arg);
		i += token_other(line, i, arg);
		i += token_var_word(line, i, arg);
		i += token_word(line, i, arg, 0);
		i += token_quote(line, i, arg);
	}
	return (0);
}
