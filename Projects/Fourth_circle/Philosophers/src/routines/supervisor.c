/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:05:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 06:09:49 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	deadline(t_philo *philo)
{
	if (get_timestamp() - philo->last_meal > philo->table->rules.time_to_die)
		return (1);
	return (0);
}

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
			printf("Philo num %d, \n\tmeals : %d\n\tTimestamp : %ld\n\n", tmp->philos[i].index,
				tmp->philos[i].meals,
				tmp->philos[i].last_meal
			);
			
			if (deadline(&tmp->philos[i]) == 1)
			{
				tmp->finish = 1;
				tmp->timestamp_start = get_timestamp();
				return (0);
			}
			i++;
		}
		printf("\n");
	}
}
