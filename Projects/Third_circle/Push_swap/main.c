/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:42:39 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:42:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **av)
{
	t_stack	*stack_a;
	char	**args;
	int		size;

	args = sanitize_entry(av);
	if (!args)
		return (0);
	stack_a = NULL;
	create_stack_a(&stack_a, args);
	size = ft_lstsize(stack_a);
	if (size <= 3)
	{
		if (size == 1)
			return (0);
		sort_aglorithm(&stack_a);
		return (0);
	}
	index_stack(&*stack_a);
	establish_cost(&*stack_a);
	mark_limits(&*stack_a);
	if (not_right_head(&stack_a) == 1)
		return 0;
	if (!is_sorted(stack_a))
		sort_aglorithm(&stack_a);
	// ft_printf("a :\n");
	// ft_lstiter(stack_a, ft_printf);
	return (free_arg(args), ft_lstfree(&stack_a), 1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	av++;
	push_swap(av);
}
