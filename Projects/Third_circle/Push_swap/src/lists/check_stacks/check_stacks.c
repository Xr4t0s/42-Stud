/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:56:58 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:56:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstiter(t_stack *lst, int (*f)(const char *, ...))
{
	while (lst)
	{
		if (lst->next == NULL)
			f("%d\n", lst->value);
		else
			f("%d, ", lst->value);
		lst = lst->next;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*bckp;

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
