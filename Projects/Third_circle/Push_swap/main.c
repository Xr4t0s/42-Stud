#include "includes/push_swap.h"

int push_swap(char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
	int 	i;
	char 	**args;

	i = 0;
	args = sanitizeEntry(av);
    stack_a = NULL;
    stack_b = NULL;
    while (args[i])
    {
        ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(args[i])));
        i++;
    }
    // av++;
    // char **arg2 = ft_split(*av, ' ');
	// i = 0;
    // while (arg2[i])
    // {
    //     ft_lstadd_back(&stack_b, ft_lstnew(ft_atoi(arg2[i])));
    //     i++;
    // }
    ft_lstiter(stack_a, ft_printf);
    ft_lstiter(stack_b, ft_printf);
	// ft_printf("Rotate the 2 piles : \n");
	// swap_a_and_b(&stack_a, &stack_b);
    push_to(&stack_a, &stack_b);
	ft_lstiter(stack_a, ft_printf);
    ft_lstiter(stack_b, ft_printf);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	free_arg(args);
	// free_arg(arg2);
	free(args);
	// free(arg2);
	return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    av++;
    push_swap(av);
}