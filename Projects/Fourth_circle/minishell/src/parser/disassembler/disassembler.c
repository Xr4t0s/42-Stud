/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:57:12 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/02 02:57:28 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_var_qmark(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

	k = 1;
	if (c[i + k] && c[i + k] == '?')
	{
		k++;
		s = ft_substr(c, i, k);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_VAR, s));
	}
	return (k);
}

int	token_var_word(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

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
			s = ft_substr(c, i, k);
			ft_lstadd_back_m(arg, ft_lstnew_m(T_VAR, s));
		}
		else
			return (token_word(c, i, arg, 1));
		if (s)
			free(s);
		return (k);
	}
	return (0);
}

int	token_quote(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

	k = 0;
	if (c[i] && c[i] == '\"')
	{
		k = 1;
		while (c[i + k] && c[i + k] != '\"')
		{
			k++;
		}
		k++;
		s = ft_substr(c, i, k);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_DQUOTE, s));
		free(s);
		return (k);
	}
	return (k);
}

int	token_other(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

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
		s = ft_substr(c, i, k);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_QUOTE, s));
		free(s);
		return (k);
	}
	return (0);
}

int	parser(char *line, t_arg **arg)
{
	int	i;

	i = 0;
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
