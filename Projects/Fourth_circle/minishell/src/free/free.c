/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:34:50 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/11 23:44:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstclear_r(t_redir **lst)
{
	t_redir	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->target)
			free ((*lst)->target);
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstclear_c(t_cmd **lst)
{
	t_cmd	*tmp;
	int		i;

	while (*lst != NULL)
	{
		i = 0;
		tmp = (*lst)->next;
		if ((*lst)->bin)
		{
			while ((*lst)->bin[i])
			{
				free((*lst)->bin[i]);
				i++;
			}
			free((*lst)->bin);
		}
		if ((*lst)->input_fd > 0)
			close((*lst)->input_fd);
		if ((*lst)->output_fd > 0)
			close((*lst)->output_fd);
		ft_lstclear_r(&(*lst)->redirection);
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstclear_m(t_arg **lst)
{
	t_arg	*current;
	t_arg	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*lst = NULL;
}
