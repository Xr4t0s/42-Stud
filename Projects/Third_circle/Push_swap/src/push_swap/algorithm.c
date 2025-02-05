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

t_stack	*size_3(t_stack *stack_a)
{
	if (stack_a->value > stack_a->next->value
		&& stack_a->value > stack_a->next->next->value)
		rotate_a_or_b(&stack_a, 1);
	else if (stack_a->value > stack_a->next->value
		&& stack_a->value < stack_a->next->next->value)
		swap_a_or_b(&stack_a, 1);
	else if (stack_a->value < stack_a->next->value
		&& stack_a->value > stack_a->next->next->value)
		reverse_rotate_a_or_b(&stack_a, 1);
	else if (stack_a->value < stack_a->next->value
		&& stack_a->value < stack_a->next->next->value)
		reverse_rotate_a_or_b(&stack_a, 1);
	if (stack_a->value > stack_a->next->value)
		swap_a_or_b(&stack_a, 1);
	return (stack_a);
}

t_stack	*algorithm(t_stack *stack_a)
{
	index_stack(stack_a);
	establish_cost(stack_a);
	ft_lstiter(stack_a, ft_printf);
	return stack_a;
}

