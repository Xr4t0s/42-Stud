#include "includes/push_swap.h"

t_stack *sort_aglorithm(t_stack *stack_a)
{
	int size;

	size = ft_lstsize(stack_a);
	if (size == 2)
	{
		if (stack_a->value > stack_a->next->value)
			swap_a_or_b(&stack_a, 1);
	}
	else if (size == 3)
	{
		if (stack_a->value > stack_a->next->value && stack_a->value > stack_a->next->next->value)
			rotate_a_or_b(&stack_a, 1);
		else if (stack_a->value > stack_a->next->value && stack_a->value < stack_a->next->next->value)
			swap_a_or_b(&stack_a, 1);
		else if (stack_a->value < stack_a->next->value && stack_a->value > stack_a->next->next->value)
		{
			swap_a_or_b(&stack_a, 0);
			reverse_rotate_a_or_b(&stack_a, 1);
		}
		else if (stack_a->value < stack_a->next->value && stack_a->value < stack_a->next->next->value)
			reverse_rotate_a_or_b(&stack_a, 1);
		if (stack_a->value > stack_a->next->value)
			swap_a_or_b(&stack_a, 1);
	}
	return (stack_a);
}

int push_swap(char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
	int 	i;
	char 	**args;
	t_stack *tmp;

	i = 0;
	args = sanitizeEntry(av);
    stack_a = NULL;
    stack_b = NULL;
    while (args[i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(args[i++])));
	if (!isSorted(stack_a))
	{
		tmp = sort_aglorithm(stack_a);
		ft_lstiter(tmp, ft_printf);
	}
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	free_arg(args);
	free(args);
	return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    av++;
    push_swap(av);
}
