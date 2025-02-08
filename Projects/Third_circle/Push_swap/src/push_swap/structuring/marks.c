/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:35:30 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/07 19:34:27 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void mark_min(t_stack *stack)
{
	t_stack *tmp;
	int		min;
	int		index;	

	tmp = stack;
	min = stack->value;
	index = stack->index;
	while(stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	stack = tmp;
	while(stack->index != index)
		stack = stack->next;
	stack->is_min = 1;
	stack = tmp;
}

static void mark_max(t_stack *stack)
{
	t_stack *tmp;
	int		max;
	int		index;	

	tmp = stack;
	max = stack->value;
	index = stack->index;
	while(stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	stack = tmp;
	while(stack->index != index)
		stack = stack->next;
	stack->is_max = 1;
	stack = tmp;
}

void mark_limits(t_stack *stack)
{
	if (stack)
	{
		mark_min(stack);
		mark_max(stack);
	}
}
