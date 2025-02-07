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
<<<<<<< HEAD
		stack_a = size_3(stack_a);
	else
		stack_a = algorithm(stack_a);
	return (stack_a);
=======
		size_3(*stack_a);
	else
		algorithm(stack_a);
>>>>>>> 96ca97ccb57fc3d7054cb87b721f09f0c2279a82
}

int	push_swap(char **av)
{
	t_stack	*stack_a;
	int		i;
	char	**args;
	long	*tmp;
	t_stack	*tmp2;

	i = 0;
	args = sanitize_entry(av);
	if (!args)
		return (0);
	stack_a = NULL;
	tmp2 = NULL;
	while (args[i])
	{
		tmp = ft_atoi2(args[i++]);
		tmp2 = ft_lstnew(tmp[0]);
		ft_lstadd_back(&stack_a, tmp2);
		free(tmp);
	}
	if (!is_sorted(stack_a))
	{
<<<<<<< HEAD
		// tmp2 = sort_aglorithm(stack_a);
		ft_lstiter(stack_a, ft_printf);
	}
	if (stack_a)
		ft_lstfree(&stack_a);
	// if (tmp2)
	// 	ft_lstfree(&tmp2);
	stack_a = NULL;
	tmp2 = NULL;
=======
		sort_aglorithm(&stack_a);
	}
	ft_printf("a = ");
	ft_lstiter(stack_a, ft_printf);
	ft_lstfree(stack_a);
>>>>>>> 96ca97ccb57fc3d7054cb87b721f09f0c2279a82
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
