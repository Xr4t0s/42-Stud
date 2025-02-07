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

void	size_3(t_stack *stack_a)
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
}

<<<<<<< HEAD
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
=======
void	desc_sort(t_stack **stack_b)
{
	if ((*stack_b)->value < (*stack_b)->next->value)
		swap_a_or_b(stack_b, -1);
>>>>>>> 96ca97ccb57fc3d7054cb87b721f09f0c2279a82
}

void create_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_to(stack_a, stack_b, -1);
	push_to(stack_a, stack_b, -1);
}

void	algorithm(t_stack **stack_a)
{
	t_stack *stack_b;

<<<<<<< HEAD
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
=======
	stack_b = NULL;
	index_stack(*stack_a);
	establish_cost(*stack_a);
	create_stack_b(stack_a, &stack_b);
	if (!is_desc_sorted(stack_b))
		desc_sort(&stack_b);
	while(!is_desc_sorted(stack_b))
	{
		
	}
	ft_printf("b = ");
	ft_lstiter(stack_b, ft_printf);
}

>>>>>>> 96ca97ccb57fc3d7054cb87b721f09f0c2279a82
