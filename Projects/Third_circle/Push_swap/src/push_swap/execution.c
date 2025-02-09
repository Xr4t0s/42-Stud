/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:21:25 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/09 20:21:25 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	current_is_lowcost_1_0(t_stack **stack,
	t_stack **stack_a,
	t_stack **stack_b)
{
	if ((*stack)->target_node->cost == 0 && (*stack)->cost == 0)
		push_to(stack_a, stack_b, -1);
	else if ((*stack)->cost >= (*stack)->target_node->cost)
	{
		while ((*stack)->target_node->cost != (*stack)->cost)
		{
			rotate_a_or_b(stack_a, 1);
			(*stack)->cost--;
		}
		while ((*stack)->cost-- != 0)
			rotate_a_and_b(stack_a, stack_b);
		push_to(stack_a, stack_b, -1);
	}
	else if ((*stack)->cost < (*stack)->target_node->cost)
	{
		while ((*stack)->target_node->cost != (*stack)->cost)
		{
			rotate_a_or_b(stack_b, -1);
			(*stack)->target_node->cost--;
		}
		while ((*stack)->target_node->cost-- != 0)
			rotate_a_and_b(stack_a, stack_b);
		push_to(stack_a, stack_b, -1);
	}
}

static void	current_is_lowcost_1_1(t_stack **stack,
	t_stack **stack_a,
	t_stack **stack_b)
{
	while ((*stack)->target_node->cost != 0)
	{
		reverse_rotate_a_or_b(stack_b, -1);
		(*stack)->target_node->cost++;
	}
	while ((*stack)->cost-- != 0)
		rotate_a_or_b(stack_a, 1);
	push_to(stack_a, stack_b, -1);
}

static void	current_is_lowcost_2_0(t_stack **stack,
	t_stack **stack_a,
	t_stack **stack_b)
{
	if ((*stack)->cost <= (*stack)->target_node->cost)
	{
		while ((*stack)->target_node->cost != (*stack)->cost)
		{
			reverse_rotate_a_or_b(stack_a, 1);
			(*stack)->cost++;
		}
		while ((*stack)->cost++ != 0)
			reverse_rotate_a_and_b(stack_a, stack_b);
		push_to(stack_a, stack_b, -1);
	}
	else if ((*stack)->cost > (*stack)->target_node->cost)
	{
		while ((*stack)->target_node->cost != (*stack)->cost)
		{
			reverse_rotate_a_or_b(stack_b, -1);
			(*stack)->target_node->cost++;
		}
		while ((*stack)->target_node->cost++ != 0)
			reverse_rotate_a_and_b(stack_a, stack_b);
		push_to(stack_a, stack_b, -1);
	}
}

static void	current_is_lowcost_2_1(t_stack **stack,
	t_stack **stack_a,
	t_stack **stack_b)
{
	if ((*stack)->target_node->cost == 0)
	{
		while ((*stack)->cost++ != 0)
			reverse_rotate_a_or_b(stack_a, 1);
		push_to(stack_a, stack_b, -1);
	}
	else
	{
		while ((*stack)->target_node->cost != 0)
		{
			rotate_a_or_b(stack_b, -1);
			(*stack)->target_node->cost--;
		}
		while ((*stack)->cost++ != 0)
			reverse_rotate_a_or_b(stack_a, 1);
		push_to(stack_a, stack_b, -1);
	}
}

void	current_is_lowcost(t_stack **stack,
	t_stack **stack_a,
	t_stack **stack_b)
{
	if ((*stack)->cost >= 0)
	{
		if ((*stack)->target_node->cost >= 0)
			current_is_lowcost_1_0(stack, stack_a, stack_b);
		else if ((*stack)->target_node->cost < 0)
			current_is_lowcost_1_1(stack, stack_a, stack_b);
	}
	else if ((*stack)->cost < 0)
	{
		if ((*stack)->target_node->cost < 0)
			current_is_lowcost_2_0(stack, stack_a, stack_b);
		else if ((*stack)->target_node->cost >= 0)
			current_is_lowcost_2_1(stack, stack_a, stack_b);
	}
}
