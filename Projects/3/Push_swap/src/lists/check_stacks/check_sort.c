/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:19:59 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/07 20:19:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *lst)
{
	t_stack	*bckp;

	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next != NULL)
	{
		if (bckp->value > bckp->next->value)
			return (0);
		bckp = bckp->next;
	}
	return (1);
}

int	is_desc_sorted(t_stack *lst)
{
	t_stack	*bckp;

	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next != NULL)
	{
		if (bckp->value < bckp->next->value)
			return (0);
		bckp = bckp->next;
	}
	return (1);
}

int	is_esc_and_desc(t_stack *lst)
{
	t_stack	*bckp;

	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next)
	{
		if (bckp->value > bckp->next->value)
			break ;
		bckp = bckp->next;
	}
	bckp = bckp->next;
	while (bckp->next)
	{
		if (bckp->value > bckp->next->value)
			return (0);
		bckp = bckp->next;
	}
	if (bckp->value > lst->value)
		return (0);
	return (1);
}

static void	current_check(t_stack **current, t_stack **min_node, int *min_cost)
{
	while (*current)
	{
		if ((*current)->is_min == 1)
		{
			*min_node = *current;
			*min_cost = (*current)->cost;
			break ;
		}
		*current = (*current)->next;
	}
}

int	not_right_head(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*min_node;
	int		min_cost;

	current = *stack_a;
	min_node = NULL;
	min_cost = 0;
	if (is_sorted(*stack_a))
		return (1);
	if (!is_esc_and_desc(*stack_a))
		return (0);
	current_check(&current, &min_node, &min_cost);
	if (!min_node)
		return (0);
	if (min_cost < 0)
	{
		while (min_cost++ != 0)
			reverse_rotate_a_or_b(stack_a, 1);
	}
	else if (min_cost > 0)
	{
		while (min_cost-- != 0)
			rotate_a_or_b(stack_a, 1);
	}
	return (1);
}
