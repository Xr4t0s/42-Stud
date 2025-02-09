/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:31:23 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 01:31:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_3(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		return (rotate_a_or_b(stack_a, 1), 1);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		return (swap_a_or_b(stack_a, 1), 1);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		return (reverse_rotate_a_or_b(stack_a, 1), 1);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value)
		return (1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a_or_b(stack_a, 1);
	else if ((*stack_a)->value < (*stack_a)->next->next->value)
	{
		rotate_a_or_b(stack_a, 1);
		swap_a_or_b(stack_a, 1);
		reverse_rotate_a_or_b(stack_a, 1);
	}
	return (1);
}

void	execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	tmp_a = *stack_a;
	while (tmp_a->next)
	{
		if (tmp_a->is_lowcost)
		{
			init_all(stack_a, stack_b);
			current_is_lowcost(&tmp_a, stack_a, stack_b);
			tmp_a = *stack_a;
			return ;
		}
		tmp_a = tmp_a->next;
	}
	if (tmp_a->is_lowcost)
		current_is_lowcost(&tmp_a, stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	init_all(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_b)->value
		&& (*stack_a)->value < ft_lstlast(*stack_b)->value)
		push_to(stack_a, stack_b, -1);
	else if ((*stack_a)->value < ft_lstlast(*stack_b)->value
		&& ft_lstlast(*stack_b)->is_min == 1)
	{
		push_to(stack_a, stack_b, -1);
		rotate_a_or_b(stack_b, -1);
	}
	else if ((*stack_b)->next && (*stack_a)->value < (*stack_b)->value
		&& (*stack_a)->value > (*stack_b)->next->value)
	{
		push_to(stack_a, stack_b, -1);
		swap_a_or_b(stack_b, -1);
	}
	else
		execute(stack_a, stack_b);
}

void	algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	create_stack_b(stack_a, &stack_b);
	if (!is_desc_sorted(stack_b))
		desc_sort(&stack_b);
	while (!is_sorted(*stack_a) || ft_lstsize(stack_b) != 0)
	{
		init_all(stack_a, &stack_b);
		sort(stack_a, &stack_b);
		if (!*stack_a)
		{
			reset_a(stack_a, &stack_b);
			return ;
		}
	}
	ft_lstfree(&stack_b);
}

void	sort_aglorithm(t_stack **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			swap_a_or_b(stack_a, 1);
	}
	else if (size == 3)
		size_3(stack_a);
	else
		algorithm(stack_a);
}
