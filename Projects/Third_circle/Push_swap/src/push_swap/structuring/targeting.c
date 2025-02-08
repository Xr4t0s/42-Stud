/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:27:23 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/07 22:27:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_target_node(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *tmp_b;
    t_stack *bckp;

    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return;

    current_a = *stack_a; // On parcourt toute la stack_a

    while (current_a) // Boucle pour traiter chaque élément de stack_a
    {
        tmp_b = *stack_b;
        bckp = *stack_b;

        // Cas où la valeur de stack_a est plus grande que la plus grande de stack_b
        if (current_a->value > (*stack_b)->value)
        {
            current_a->target_node = tmp_b;
        }
        else
        {
            // Chercher le bon target_node dans stack_b
            while (tmp_b->next)
            {
                if (current_a->value < tmp_b->value
                    && current_a->value > tmp_b->next->value)
				{
                    current_a->target_node = tmp_b->next;
					break;
				}
                tmp_b = tmp_b->next;
            }

            // Si aucun élément ne correspond, on prend le plus petit élément de stack_b
            if (current_a->value < tmp_b->value && tmp_b->is_min > 0 && !current_a->target_node)
                current_a->target_node = bckp;
        }
		
        // Passer au prochain élément de stack_a
        current_a = current_a->next;
    }
}

