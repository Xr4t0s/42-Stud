/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:09:30 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/04 06:57:12 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_arg(t_parse *parse, int len, t_arg **arg, t_token_type type)
{
	char	*s;
	
	s = ft_substr(parse->s, parse->i, len); // carré
	if (!s)
		return ;
	ft_lstadd_back_m(arg, ft_lstnew_m(type, s));
	free(s);
}

int	check_cmd(t_parse *parse, t_arg **arg, int o)
{
	int		k;
	int		q;
	int		tmp;

	k = 0;
	q = 0;
	tmp = 0;
	(void)o;
	while (parse->s[parse->i] && parse->s[parse->i] == ' ')
	{
		k++;
		parse->i++;
	}
	while (parse->s[parse->i + tmp] && !(parse->s[parse->i + tmp] == '<'
			|| parse->s[parse->i + tmp] == '>' || parse->s[parse->i + tmp] == '='
			|| parse->s[parse->i + tmp] == ' ' || parse->s[parse->i + tmp] == '|'
			|| parse->s[parse->i + tmp] == '$'))
	{
		if (parse->s[parse->i + tmp] == '\"' || parse->s[parse->i + tmp] == '\'')
		{
			if (parse->s[parse->i + tmp] == '\"')
			{
				tmp++;
				k++;
				while (parse->s[parse->i + tmp] && parse->s[parse->i + tmp] != '\"')
					tmp++;
			}
			if (parse->s[parse->i + tmp] == '\'')
			{
				tmp++;
				k++;
				while (parse->s[parse->i + tmp] && parse->s[parse->i + tmp] != '\'')
					tmp++;
			}
			q = 1;
		}
		tmp++;
	}
	if (parse->s[parse->i + k] != '|' && parse->s[parse->i + k] != '$')
		append_arg(parse, (tmp), arg, T_WORD);
	return (tmp);
}
