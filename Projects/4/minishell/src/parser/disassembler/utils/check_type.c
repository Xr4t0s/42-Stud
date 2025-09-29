/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 03:46:04 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 03:46:26 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_type(t_arg *arg)
{
	if (arg->type == T_WORD || arg->type == T_QUOTE
		|| arg->type == T_DQUOTE || arg->type == T_VAR
		|| check_token_redir(arg->type))
		return (1);
	return (0);
}

int	check_type2(t_arg *arg)
{
	if ((!arg->next || !(arg->next->type == T_WORD
				|| arg->next->type == T_QUOTE
				|| arg->next->type == T_DQUOTE)))
		return (1);
	return (0);
}
