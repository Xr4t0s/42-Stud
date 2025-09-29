/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:39 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:32:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*bckp;

	bckp = *lst;
	while (*lst)
	{
		bckp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = bckp;
	}
	*lst = NULL;
}
