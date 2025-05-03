/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:09:30 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/03 04:31:11 by engiacom         ###   ########.fr       */
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

	i = 0;
	k = 0;
	while (s[i] && s[i] == ' ')
	{
		k++;
		i++;
	}
	while (s[i] && !(s[i] == '<' || s[i] == '>' || s[i] == '=' || s[i] == ' ' || s[i] == '|' || s[i] == '$'))
	{
		if (s[i] == '\"')
		{
			i++;
			while (s[i] && s[i] != '\"')
				i++;
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		i++;
	}
	if (s[k] != '|' && s[k] != '$')
		append_arg(s, k, i - k, arg, T_WORD);
	return (i);
}
