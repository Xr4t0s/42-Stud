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
		size_3(*stack_a);
	else
		algorithm(stack_a);
}

int	push_swap(char **av)
{
	t_stack	*stack_a;
	int		i;
	char	**args;
	long	*tmp;

	i = 0;
	args = sanitize_entry(av);
	if (!args)
		return (0);
	stack_a = NULL;
	while (args[i])
	{
		tmp = ft_atoi2(args[i++]);
		ft_lstadd_back(&stack_a, ft_lstnew(tmp[0]));
		free(tmp);
	}
	if (!is_sorted(stack_a))
	{
		sort_aglorithm(&stack_a);
	}
	ft_printf("a = ");
	ft_lstiter(stack_a, ft_printf);
	ft_lstfree(stack_a);
	free_arg(args);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	av++;
	push_swap(av);
}
