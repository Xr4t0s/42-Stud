/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:27:23 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/07 22:27:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*is_upper_than_max(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack_b;
	while (tmp->next)
	{
		if (tmp->is_max)
			max = tmp;
		tmp = tmp->next;
	}
	if (tmp->is_max)
		max = tmp;
	return (max);
}

static t_stack	*is_lower_than_min(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack_b;
	while (tmp->next)
	{
		if (tmp->is_min)
			min = tmp;
		tmp = tmp->next;
	}
	if (tmp->is_min)
		min = tmp;
	return (min);
}

static void	find_target_node_utils(t_stack **current_a,
	t_stack **tmp_b,
	t_stack **bckp)
{
	while ((*tmp_b)->next)
	{
		if ((*current_a)->value < (*tmp_b)->value
			&& (*current_a)->value > (*tmp_b)->next->value)
		{
			(*current_a)->target_node = (*tmp_b)->next;
			break ;
		}
		else if ((*current_a)->value > (*tmp_b)->value
			&& (*current_a)->value < ft_lstlast(*tmp_b)->value)
		{
			(*current_a)->target_node = *tmp_b;
			break ;
		}
		*tmp_b = (*tmp_b)->next;
	}
	if ((*current_a)->value < (*tmp_b)->value
		&& (*tmp_b)->is_min > 0 && !(*current_a)->target_node)
		(*current_a)->target_node = *bckp;
}

void	find_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*tmp_b;
	t_stack	*bckp;
	t_stack	*tmp_u;
	t_stack	*tmp_l;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_a = *stack_a;
	while (current_a)
	{
		tmp_b = *stack_b;
		bckp = *stack_b;
		tmp_u = is_upper_than_max(stack_b);
		tmp_l = is_lower_than_min(stack_b);
		if (current_a->value > tmp_u->value)
			current_a->target_node = tmp_u;
		else if (current_a->value < tmp_l->value)
			current_a->target_node = tmp_u;
		else
			find_target_node_utils(&current_a, &tmp_b, &bckp);
		current_a = current_a->next;
	}
}
