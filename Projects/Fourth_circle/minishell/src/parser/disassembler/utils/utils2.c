/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:09:30 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/04 00:50:43 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_arg(char *c, int start, int len, t_arg **arg, t_token_type type)
{
	char	*s;
	
	s = ft_substr(c, start, len);
	if (!s)
		return ;
	ft_lstadd_back_m(arg, ft_lstnew_m(type, s));
	free(s);
}

int	check_cmd(char *s, t_arg **arg)
{
	int		i;
	int		k;
	int		q;

	i = 0;
	k = 0;
	q = 0;
	while (s[i] && s[i] == ' ')
	{
		k++;
		i++;
	}
	while (s[i] && !(s[i] == '<' || s[i] == '>' || s[i] == '=' || s[i] == ' ' || s[i] == '|' || s[i] == '$'))
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			if (s[i] == '\"')
			{
				i++;
				k++;
				while (s[i] && s[i] != '\"')
					i++;
			}
			if (s[i] == '\'')
			{
				i++;
				k++;
				while (s[i] && s[i] != '\'')
					i++;
			}
			q = 1;
		}
		i++;
	}
	if (s[k] != '|' && s[k] != '$')
	{
		append_arg(s, k, (i - k) - q, arg, T_WORD);
	}
	return (i);
}
