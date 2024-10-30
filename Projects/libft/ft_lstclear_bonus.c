/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:24:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 15:24:31 by marvin           ###   ########.fr       */
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
