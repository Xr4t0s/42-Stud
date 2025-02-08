/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:58:28 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:58:28 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*bckp;

	if (!lst)
		return (NULL);
	bckp = lst;
	while (bckp->next != NULL)
		bckp = bckp->next;
	return (bckp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void create_stack_a(t_stack **stack_a, char **args)
{
	int		i;
	long	*tab;
	t_stack *tmp_stack;

	i = 0;
	while (args[i])
	{
		tab = ft_atoi2(args[i++]);
		tmp_stack = ft_lstnew(tab[0]);
		ft_lstadd_back(stack_a, tmp_stack);
		free(tab);
	}
}

void create_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_to(stack_a, stack_b, -1);
	push_to(stack_a, stack_b, -1);
}
