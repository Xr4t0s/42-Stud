/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 07:12:26 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/12 00:11:12 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_unquote(char *str, int start, int end)
{
	char	*start_s;
	char	*mid_s;
	char	*end_s;
	char	*ret;
	char	*tmp;

	if (start == 0 && end == (int)ft_strlen(str) - 1)
	{
		ret = ft_substr(str, 1, ft_strlen(str) - 2);
		return (free(str), ret);
	}
	if (start == 0)
		start_s = ft_calloc(8, 1);
	else
		start_s = ft_substr(str, 0, start);
	mid_s = ft_substr(str, start + 1, (end - start - 1));
	end_s = ft_substr(str, end + 1, ft_strlen(str) - end);
	ret = ft_strjoin(start_s, mid_s);
	tmp = ft_strjoin(ret, end_s);
	return (free(start_s), free(mid_s), free(end_s), free(str), free(ret), tmp);
}

int	init_dequote(t_dequote *d, char *tmp, int start)
{
	d->q = 0;
	d->dq = 0;
	d->end = 0;
	d->str = tmp;
	while (d->str[start] && d->str[start] != '\"' && d->str[start] != '\'')
		start++;
	if (d->str[start] == '\"' && d->q == 0)
		d->dq = 1;
	else if (d->str[start] == '\'' && d->dq == 0)
		d->q = 1;
	return (start);
}

char	*dequote(char *tmp, int start)
{
	t_dequote	d;

	if (start < 0)
		start = 0;
	start = init_dequote(&d, tmp, start);
	if (d.q == 1)
	{
		if (!d.str[start + 1])
			return (tmp);
		d.end = start + 1;
		while (d.str[d.end] != '\'')
			d.end++;
	}
	else if (d.dq == 1)
	{
		if (!d.str[start + 1])
			return (tmp);
		d.end = start + 1;
		while (d.str[d.end] != '\"')
			d.end++;
	}
	if (!d.str[start])
		return (tmp);
	return (tmp = ft_unquote(tmp, start, d.end),
		start = d.end - 2, dequote(tmp, start));
}

void	slash(t_arg **arg)
{
	t_arg	*tmp;

	tmp = *arg;
	while (tmp)
	{
		tmp->value = dequote(tmp->value, 0);
		tmp = tmp->next;
	}
}
