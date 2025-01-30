#include "push_swap.h"

int rotate_a_or_b(t_stack **stack, int a_or_b)
{
    t_stack *tmp;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return (0);
    tmp = *stack;
	*stack = (*stack)->next;
	last = tmp;
    while(last->next != NULL)
	{
        last = last->next;
	}
	last->next = tmp;
    tmp->next = NULL;
	if (a_or_b == 1)
		ft_printf("ra\n");
	else if (a_or_b == -1)
		ft_printf("rb\n");
	else if (a_or_b == 2)
		ft_printf("rr\n");
    return (1);
}

int rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		if (!(*stack_a)->next->value || !(*stack_b)->next->value)
			return (0);
		if (!rotate_a_or_b(stack_a, 2) || !rotate_a_or_b(stack_b, 0))
			return (0);
	}
    return (1);
}

int reverse_rotate_a_or_b(t_stack **stack, int a_or_b)
{
    t_stack *tmp;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return (0);
    tmp = *stack;
    last = ft_lstlast(*stack);
    while (tmp->next != last)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
	if (a_or_b == 1)
		ft_printf("rra\n");
	else if (a_or_b == -1)
		ft_printf("rrb\n");
	else if (a_or_b == 2)
		ft_printf("rrr\n");
    return (1);
}

int reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		if (!(*stack_a)->next->value || !(*stack_b)->next->value)
			return (0);
		if (!reverse_rotate_a_or_b(stack_a, 2) || !reverse_rotate_a_or_b(stack_b, 0))
			return (0);
	}
    return (1);
}
