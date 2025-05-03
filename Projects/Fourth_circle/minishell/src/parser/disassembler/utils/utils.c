/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:14:32 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/03 03:07:23 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*ft_lstnew_m(t_token_type type, char *value)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_m(t_arg **lst, t_arg *new)
{
	t_arg	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	token_r_right(char *c, int i, t_arg **arg)
{
	if (c[i] && c[i] == '>')
	{
		if (c[i + 1] && c[i + 1] == '>')
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_APPEND, ">>"));
			return (2);
		}
		else
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_R_OUT, ">"));
			return (1);
		}
	}
	return (0);
}

int	token_r_left(char *c, int i, t_arg **arg)
{
	if (c[i] && c[i] == '<')
	{
		if (c[i + 1] && c[i + 1] == '<')
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_HEREDOC, "<<"));
			return (2);
		}
		else
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_R_IN, "<"));
			return (1);
		}
	}
	return (0);
}

int	token_word(char *c, int i, t_arg **arg, int v)
{
	int		k;

	k = v;
	while (c[i + k] && !(is_separator(c[i + k])))
		k++;
	if (k > 0)
	{
		append_arg(c, i, k, arg, T_WORD);
		return (k);
	}
	return (k);
}
