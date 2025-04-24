/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:05:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 01:18:46 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*supervisor(void *supervisor)
{
	t_table *tmp;
	int		i;

	tmp = (t_table *)supervisor;
	while (1)
	{
		i = 0;
		while (i < tmp->rules.philos)
		{
			if (tmp->philos[i].dead_or_alive)
			{
				tmp->finish = 1;
				return (0);
			}
			i++;
		}
	}
}
