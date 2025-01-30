#include "push_swap.h"

int swap_a_or_b(t_stack **stack)
{
    t_stack *tmp;

    if (!*stack || !(*stack)->next)
        return (0);
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
    return (1);
}

int swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!swap_a_or_b(stack_a) || !swap_a_or_b(stack_b))
        return (0);
    return (1);
}

int push_to(t_stack **stack_from, t_stack **stack_to)
{
    t_stack *tmp;

    if (!*stack_from)
        return (0);
    tmp = (*stack_from)->next;
    (*stack_from)->next = *stack_to;
    *stack_to = *stack_from;
    *stack_from = tmp;
    return (1);
}

