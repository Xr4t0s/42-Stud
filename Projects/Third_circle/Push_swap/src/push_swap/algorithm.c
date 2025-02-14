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

static void	final_sort_utils(t_stack **tmp,
		t_stack **stack_a,
		t_stack **stack_b)
{
	if ((*tmp)->value < (*stack_a)->value && (*tmp)->value > (*stack_b)->value)
	{
		reverse_rotate_a_or_b(stack_a, 1);
		*tmp = ft_lstlast(*stack_a);
	}
	else
		push_to(stack_b, stack_a, 1);
}

static void	final_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;

	size_15(stack_a, stack_b, size - 3);
	init_all(stack_a, stack_b);
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
		final_sort_utils(&tmp, stack_a, stack_b);
	while ((*stack_a)->value > ft_lstlast(*stack_a)->value)
		reverse_rotate_a_or_b(stack_a, 1);
}

void	algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	create_stack_b(stack_a, &stack_b);
	if (!is_desc_sorted(stack_b))
		desc_sort(&stack_b);
	while (!is_sorted(*stack_a) || stack_b)
	{
		init_all(stack_a, &stack_b);
		if (ft_lstsize(*stack_a) <= 15 && stack_b)
		{
			final_sort(stack_a, &stack_b, ft_lstsize(*stack_a));
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
	else if (size == 4)
		size_4(stack_a);
	else if (size == 5)
		size_5(stack_a);
	else
		algorithm(stack_a);
}
