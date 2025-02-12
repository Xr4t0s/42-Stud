/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:34 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:33:34 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*bckp;

	i = 0;
	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next != NULL)
	{
		bckp = bckp->next;
		i++;
	}
	i++;
	return (i);
}
