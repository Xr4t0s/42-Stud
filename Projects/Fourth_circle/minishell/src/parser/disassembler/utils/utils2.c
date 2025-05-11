/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:09:30 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/11 04:23:33 by nitadros         ###   ########.fr       */
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

int	check_cmd_utils(t_parse *prs, int tmp, int c)
{
	tmp++;
	while (prs->s[prs->i + tmp] && prs->s[prs->i + tmp] != c)
		tmp++;
	return (tmp);
}

int	check_cmd(t_parse *prs, t_arg **arg)
{
	int		tmp;

	tmp = 0;
	while (prs->s[prs->i + tmp] && !(prs->s[prs->i + tmp] == '<'
			|| prs->s[prs->i + tmp] == '>' || prs->s[prs->i + tmp] == ' '
			|| prs->s[prs->i + tmp] == '|' || prs->s[prs->i + tmp] == '$'))
	{
		if (prs->s[prs->i + tmp] == '\"' || prs->s[prs->i + tmp] == '\'')
		{
			if (prs->s[prs->i + tmp] == '\"')
				tmp = check_cmd_utils(prs, tmp, '\"');
			if (prs->s[prs->i + tmp] == '\'')
				tmp = check_cmd_utils(prs, tmp, '\'');
		}
		tmp++;
	}
	if (tmp > 0)
		append_arg(prs, (tmp), arg, T_WORD);
	return (tmp);
}

void	init_parse(t_parse *parse)
{
	parse->i = 0;
	parse->start = 0;
	parse->len = 0;
}

t_arg	*ft_lstlast_a(t_arg *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
