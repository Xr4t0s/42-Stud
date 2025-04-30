/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:14:32 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 04:14:53 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '|' || c == '<' || c == '>' || 
	        c == '\'' || c == '\"' || c == '$');
}

t_arg	*ft_lstnew_m(t_token_type type, char *value)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_m(t_arg **arg, t_arg *new)
{
	t_arg	*tmp;

	if (*arg == NULL)
		*arg = new;
	else
	{
		tmp = *arg;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
