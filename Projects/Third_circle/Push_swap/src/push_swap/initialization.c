/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:24:30 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/09 20:24:30 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_all(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(*stack_a);
	index_stack(*stack_b);
	mark_limits(*stack_a);
	mark_limits(*stack_b);
	establish_cost(*stack_a);
	establish_cost(*stack_b);
	find_target_node(stack_a, stack_b);
	find_target_node(stack_b, stack_a);
	establish_cost_to_swap(stack_a);
	establish_cost_to_swap(stack_b);
}

void	reset_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	index_stack(*stack_b);
	establish_cost(*stack_b);
	mark_limits(*stack_b);
	tmp = is_upper_than_max(stack_b);
	if (tmp->cost < 0)
	{
		while (tmp->cost++ != 0)
			reverse_rotate_a_or_b(stack_b, -1);
	}
	else
	{
		while (tmp->cost-- != 0)
			rotate_a_or_b(stack_b, -1);
	}
	while (*stack_b)
		push_to(stack_b, stack_a, 1);
	return ;
}
