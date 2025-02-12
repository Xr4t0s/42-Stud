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

void size_5(t_stack **a, t_stack **b)
{
	mark_limits(*a);
	while(!(*a)->is_min)
		reverse_rotate_a_or_b(a, 1);
	push_to(a, b, -1);
	mark_limits(*a);
	while(!(*a)->is_min)
		reverse_rotate_a_or_b(a, 1);
	push_to(a, b, -1);
	size_3(a);
	push_to(b, a, 1);
	push_to(b, a, 1);
}

int	size_3(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
	{
		if ((*stack_a)->next->value < (*stack_a)->next->next->value)
			return (rotate_a_or_b(stack_a, 1), 1);
		return (rotate_a_or_b(stack_a, 1), swap_a_or_b(stack_a, 1), 1);
	}
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

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	if (!*stack_a || !stack_a)
		return ;
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	tmp_a = *stack_a;
	while (tmp_a->next)
	{
		if (tmp_a->is_lowcost)
		{
			current_is_lowcost(&tmp_a, stack_a, stack_b);
			tmp_a = *stack_a;
			return ;
		}
		tmp_a = tmp_a->next;
	}
	if (tmp_a->is_lowcost)
		current_is_lowcost(&tmp_a, stack_a, stack_b);
}

static void	final_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	//size_3(stack_a);
	size_5(stack_a, stack_b);
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
	tmp = ft_lstlast(*stack_a);
	while (tmp->value > (*stack_b)->value)
	{
		reverse_rotate_a_or_b(stack_a, 1);
		tmp = ft_lstlast(*stack_a);
	}
	while (*stack_b)
	{
		if (tmp->value < (*stack_a)->value && tmp->value > (*stack_b)->value)
		{
			reverse_rotate_a_or_b(stack_a, 1);
			tmp = ft_lstlast(*stack_a);
		}
		else
			push_to(stack_b, stack_a, 1);
	}
	if ((*stack_a)->value > ft_lstlast(*stack_a)->value)
		reverse_rotate_a_or_b(stack_a, 1);
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
		if (ft_lstsize(*stack_a) <= 5)
		{
			final_sort(stack_a, &stack_b);
			return ;
		}
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
