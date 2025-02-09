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

static void init_all(t_stack **stack_a, t_stack **stack_b)
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

static void	current_is_lowcost(t_stack **stack, t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack)->cost >= 0)
	{
		if((*stack)->target_node->cost >= 0)
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
		else if((*stack)->target_node->cost < 0)
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
	}
	else if ((*stack)->cost < 0)
	{
		if ((*stack)->target_node->cost < 0)
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
		else if((*stack)->target_node->cost >= 0)
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
	}
}

void execute(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	tmp_a = *stack_a;
	while(tmp_a->next)
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

void sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	init_all(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_b)->value && (*stack_a)->value < ft_lstlast(*stack_b)->value)
		push_to(stack_a, stack_b, -1);
	else if((*stack_a)->value < ft_lstlast(*stack_b)->value && ft_lstlast(*stack_b)->is_min == 1)
	{
		push_to(stack_a, stack_b, -1);
		rotate_a_or_b(stack_b, -1);
	}
	else if((*stack_b)->next && (*stack_a)->value < (*stack_b)->value
		&& (*stack_a)->value > (*stack_b)->next->value)
	{
		push_to(stack_a, stack_b, -1);
		swap_a_or_b(stack_b, -1);
	}
	else
		execute(stack_a, stack_b);
	// ft_printf("stack b = ");
	// ft_lstiter(*stack_b, ft_printf);
	// ft_printf("stack a = ");
	// ft_lstiter(*stack_a, ft_printf);
}

void	algorithm(t_stack **stack_a)
{
	t_stack *stack_b;
	t_stack	*tmp;
	t_stack	*tmp2;

	stack_b = NULL;
	tmp = NULL;
	create_stack_b(stack_a, &stack_b);
	if (!is_desc_sorted(stack_b))
		desc_sort(&stack_b);
	while(!is_sorted(*stack_a) || ft_lstsize(stack_b) != 0)
	{
		init_all(stack_a, &stack_b);
		sort(stack_a, &stack_b);
		if (!*stack_a)
		{
			index_stack(stack_b);
			establish_cost(stack_b);
			mark_limits(stack_b);
			tmp = is_upper_than_max(&stack_b);
			tmp2 = stack_b;
			while (tmp2 && tmp2 != tmp)
    			tmp2 = tmp2->next;
			if (tmp->cost < 0)
			{
				int cost = tmp->cost;
				while(cost != 0)
				{
					reverse_rotate_a_or_b(&stack_b, -1);
					cost++;
				}
			}
			else
			{
				while(tmp->cost != 0)
				{
					rotate_a_or_b(&stack_b, -1);
					tmp->cost--;
				}
			}
			while (stack_b)
				push_to(&stack_b, stack_a, 1);
			return ;
		}
		// ft_lstiter(*stack_a, ft_printf);
	}
	ft_lstfree(&stack_b);
}

