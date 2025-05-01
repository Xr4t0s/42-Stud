/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:34:50 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 16:23:18 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_m(t_arg **lst)
{
	t_arg	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*lst)->type = 0;
		if ((*lst)->value)
		{
			(*lst)->value = NULL;
			free ((*lst)->value);
		}
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}
