/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   establish_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:56:29 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/05 21:54:15 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void modulo_costing(t_stack *stack, int median, int size)
{
	int i;

	i = 0;
	median++;
	while (stack->index != median + 1)
	{
		stack->cost = i;
		i++;
		stack = stack->next;
	}
	i--;
	while (stack->index != size)
	{
		stack->cost = -i;
		i--;
		stack = stack->next;
	}
	stack->cost = -i;
}

static void no_modulo_costing(t_stack *stack, int median, int size)
{
	int i;

	i = 0;
	while (stack->index != median + 1)
	{
		stack->cost = i;
		i++;
		stack = stack->next;
	}
	while (stack->index != size)
	{
		stack->cost = -i;
		i--;
		stack = stack->next;
	}
	stack->cost = -i;
}

void    establish_cost(t_stack *stack)
{
	int stack_size;
	int modulo;
	int median;

	stack_size = ft_lstsize(stack);
	modulo = stack_size % 2;
	median = stack_size / 2;
	if (modulo == 1)
		modulo_costing(stack, median, stack_size);
	else
		no_modulo_costing(stack, median, stack_size);
}