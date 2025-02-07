/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:00:42 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 01:00:42 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a_or_b(t_stack **stack, int a_or_b)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (a_or_b == 1)
		ft_printf("sa\n");
	else if (a_or_b == -1)
		ft_printf("sb\n");
	else if (a_or_b == 2)
		ft_printf("ss\n");
	return (1);
}

int	swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		if (!swap_a_or_b(stack_a, 2) || !swap_a_or_b(stack_b, 0))
			return (0);
	}
	return (1);
}

int	push_to(t_stack **stack_from, t_stack **stack_to, int a_or_b)
{
	t_stack	*tmp;

	if (!*stack_from)
		return (0);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
	if (a_or_b == 1)
		ft_printf("pa\n");
	else if (a_or_b == -1)
		ft_printf("pb\n");
	return (1);
}
