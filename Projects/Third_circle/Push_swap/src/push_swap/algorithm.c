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

static t_stack *reverse_size3(t_stack *stack_b)
{
	if (stack_b->value < stack_b->next->value
		&& stack_b->value < stack_b->next->next->value)
		rotate_a_or_b(&stack_b, -1);
	else if (stack_b->value < stack_b->next->value
		&& stack_b->value > stack_b->next->next->value)
		swap_a_or_b(&stack_b, -1);
	else if (stack_b->value > stack_b->next->value
		&& stack_b->value < stack_b->next->next->value)
		reverse_rotate_a_or_b(&stack_b, -1);
	else if (stack_b->value > stack_b->next->value
		&& stack_b->value > stack_b->next->next->value)
		reverse_rotate_a_or_b(&stack_b, -1);
	if (stack_b->value < stack_b->next->value)
		swap_a_or_b(&stack_b, -1);
	return (stack_b);
}

// t_stack *establish_cost(t_stack *stack_a)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	i = 0;
// 	tmp = stack_a;
// 	while (tmp)
// 	{
// 		tmp->cost = i;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (stack_a);
// }

t_stack	*algorithm(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		i;

	i = 0;
	stack_b = NULL;
	while (i++ < 3)
		push_to(&stack_a, &stack_b, -1);
	if (!is_sorted(stack_b))
		stack_b = reverse_size3(stack_b);
	return (stack_b);
}
