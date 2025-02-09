/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:09:16 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/09 20:42:43 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
	stack->index = i;
}
