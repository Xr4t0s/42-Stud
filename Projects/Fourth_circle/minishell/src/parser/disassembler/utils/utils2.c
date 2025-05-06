/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:09:30 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/06 18:58:41 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_arg(t_parse *parse, int len, t_arg **arg, t_token_type type)
{
	char	*s;

	s = ft_substr(parse->s, parse->i, len);
	if (!s)
		return ;
	ft_lstadd_back_m(arg, ft_lstnew_m(type, s));
	free(s);
}

int	check_cmd(t_parse *prs, t_arg **arg, int o)
{
	int		k;
	int		q;
	int		tmp;

	k = 0;
	q = 0;
	tmp = 0;
	(void)o;
	while (prs->s[prs->i + tmp] && !(prs->s[prs->i + tmp] == '<'
			|| prs->s[prs->i + tmp] == '>' || prs->s[prs->i + tmp] == ' '
			|| prs->s[prs->i + tmp] == '|' || prs->s[prs->i + tmp] == '$'))
	{
		if (prs->s[prs->i + tmp] == '\"' || prs->s[prs->i + tmp] == '\'')
		{
			if (prs->s[prs->i + tmp] == '\"')
			{
				tmp++;
				k++;
				while (prs->s[prs->i + tmp] && prs->s[prs->i + tmp] != '\"')
					tmp++;
			}
			if (prs->s[prs->i + tmp] == '\'')
			{
				tmp++;
				k++;
				while (prs->s[prs->i + tmp] && prs->s[prs->i + tmp] != '\'')
					tmp++;
			}
			q = 1;
		}
		tmp++;
	}
	if (tmp > 0)
		append_arg(prs, (tmp), arg, T_WORD);
	return (tmp);
}
