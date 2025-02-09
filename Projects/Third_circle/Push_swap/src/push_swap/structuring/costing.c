/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:56:29 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/09 04:14:27 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void modulo_costing(t_stack *stack, int median, int size)
{
	int i;

	i = 0;
	median++;
	if (!stack)
		return ;
	while (stack->index != median + 1 && stack)
	{
		stack->cost = i;
		i++;
		stack = stack->next;
	}
	i--;
	while (stack->index != size && stack)
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
	if (!stack)
		return ;
	while (stack->index != median + 1 && stack)
	{
		stack->cost = i;
		i++;
		stack = stack->next;
	}
	if (stack->next)
		stack->next->is_mid = 1;
	while (stack->index != size && stack)
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
	if (stack_size == 1)
	{	
		stack->cost = 0;
		return ;
	}
	modulo = stack_size % 2;
	median = stack_size / 2;
	if (modulo == 1)
		modulo_costing(stack, median, stack_size);
	else
		no_modulo_costing(stack, median, stack_size);
}

void establish_cost_to_swap(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (!tmp || !tmp->target_node)
			return ;
		if (tmp->cost >= 0 && tmp->target_node->cost >= 0)
		{
			if (tmp->cost >= tmp->target_node->cost)
				tmp->cost_to_swap = tmp->cost + 1;
			else if (tmp->cost < tmp->target_node->cost)
				tmp->cost_to_swap = tmp->target_node->cost + 1;
		}
		else if (tmp->cost < 0 && tmp->target_node->cost < 0)
		{
			if (tmp->cost <= tmp->target_node->cost)
				tmp->cost_to_swap = tmp->cost - 1;
			else if (tmp->cost > tmp->target_node->cost)
				tmp->cost_to_swap = -tmp->cost + -tmp->target_node->cost + 1;
		}
		else
		{
			if(tmp->cost >= 0 && tmp->target_node->cost < 0)
				tmp->cost_to_swap = tmp->cost + -tmp->target_node->cost + 1;
			else if(tmp->cost < 0 && tmp->target_node->cost >= 0)
				tmp->cost_to_swap = -tmp->cost + tmp->target_node->cost + 1;
		}
		tmp = tmp->next;
	}
	mark_lowcost(stack);
}
