#include "push_swap.h"

int rotate_a_or_b(t_stack **stack)
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
    return (1);
}

int rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!rotate_a_or_b(stack_a) || !rotate_a_or_b(stack_b))
        return (0);
    return (1);
}

int reverse_rotate_a_or_b(t_stack **stack)
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
    return (1);
}

int reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!reverse_rotate_a_or_b(stack_a) || !reverse_rotate_a_or_b(stack_b))
        return (0);
    return (1);
}
