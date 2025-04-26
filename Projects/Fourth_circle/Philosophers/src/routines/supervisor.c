/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:05:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/26 05:02:10 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	deadline(t_philo *philo)
{
	if (get_timestamp() - philo->last_meal > philo->table->rules.time_to_die)
	{
		printf("%ld\n", philo->last_meal);
		return (1);
	}
	return (0);
}

// static int	all_eaten(t_philo *philo)
// {
// 	if (philo->meals >= philo->table->rules.number_eat && philo->table->rules.number_eat != -1)
// 		return (1);
// 	return (0);
// }

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
			if (deadline(&tmp->philos[i]) == 1)
			{
				printf("n %d - meal %d\n", i, tmp->philos[i].meals);
				tmp->finish = 1;
				tmp->timestamp_start = get_timestamp();
				return (0);
			}
			i++;
		}
		usleep(100);
	}
}
