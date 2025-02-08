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

void	size_3(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		rotate_a_or_b(stack_a, 1);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		swap_a_or_b(stack_a, 1);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
		reverse_rotate_a_or_b(stack_a, 1);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a_or_b(stack_a, 1);
}

// void execute(t_stack **stack_a, t_stack **stack_b)
// {

// }

void sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("stack b = ");
	ft_lstiter(*stack_b, ft_printf);
	ft_printf("stack a = ");
	ft_lstiter(*stack_a, ft_printf);
	if ((*stack_a)->value > (*stack_b)->value)
		push_to(stack_a, stack_b, -1);
	else if((*stack_a)->value < ft_lstlast(*stack_b)->value)
	{
		push_to(stack_a, stack_b, -1);
		rotate_a_or_b(stack_b, -1);
	}
	else
	{
		find_target_node(stack_a, stack_b);
		establish_cost_to_swap(stack_a);
		// ft_lstiter(*stack_a, ft_printf);
	}
}

void	algorithm(t_stack **stack_a)
{
	t_stack *stack_b;
	int i = 0;

	stack_b = NULL;
	create_stack_b(stack_a, &stack_b);
	if (!is_desc_sorted(stack_b))
		desc_sort(&stack_b);
	while(!is_sorted(*stack_a) || ft_lstsize(stack_b) != 0)
	{
		if (ft_lstsize(*stack_a) > 1)
		{
			index_stack(*stack_a);
			establish_cost(*stack_a);
			mark_limits(*stack_a);
		}
		if (ft_lstsize(stack_b) > 1)
		{	
			index_stack(stack_b);
			establish_cost(stack_b);
			mark_limits(stack_b);
		}
		if (!*stack_a && is_desc_sorted(stack_b))
		{
			while(stack_b->next)
				push_to(&stack_b, stack_a, 1);
			if (!stack_b->next)
				push_to(&stack_b, stack_a, 1);
			return ;
		}
		sort(stack_a, &stack_b);
		i++;
		if (i == 10)
		{
			ft_lstiter(stack_b, ft_printf);
			break;
		}
	}
	ft_lstfree(&stack_b);
}

