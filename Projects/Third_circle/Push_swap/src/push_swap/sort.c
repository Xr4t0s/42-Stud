/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:23:12 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/12 14:23:12 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_5(t_stack **a, t_stack **b, int size)
{
	int		tmp;
	t_stack	*tmp_min;

	tmp = size;
	tmp_min = NULL;
	while (tmp-- != 0)
	{
		init_all(a, b);
		tmp_min = is_lower_than_min(a);
		if (tmp_min->cost < 0)
		{
			while (tmp_min->cost++ != 0)
				reverse_rotate_a_or_b(a, 1);
		}
		else
		{
			while (tmp_min->cost-- != 0)
				rotate_a_or_b(a, 1);
		}
		push_to(a, b, -1);
	}
	size_3(a);
	tmp = size;
	while (tmp-- != 0)
		push_to(b, a, 1);
}

int	size_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		if ((*a)->next->value < (*a)->next->next->value)
			return (rotate_a_or_b(a, 1), 1);
		return (rotate_a_or_b(a, 1), swap_a_or_b(a, 1), 1);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		return (swap_a_or_b(a, 1), 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		return (reverse_rotate_a_or_b(a, 1), 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		return (1);
	if ((*a)->value > (*a)->next->value)
		swap_a_or_b(a, 1);
	else if ((*a)->value < (*a)->next->next->value)
		return (rotate_a_or_b(a, 1), swap_a_or_b(a, 1),
			reverse_rotate_a_or_b(a, 1));
	return (1);
}
