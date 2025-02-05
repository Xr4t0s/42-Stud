/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:09:16 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/05 20:50:35 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    index_stack(t_stack *stack)
{
	int i;

	i = 1;
	while(stack->next != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
	stack->index = i;
}
