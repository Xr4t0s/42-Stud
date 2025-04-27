/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:05:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/27 04:32:12 by nitadros         ###   ########.fr       */
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

static int	all_eaten(t_philo *philo)
{
	if (philo->meals >= philo->table->rules.number_eat
		&& philo->table->rules.number_eat != -1)
		return (1);
	return (0);
}

static int	dead_or_alive(t_philo *philos)
{
	if (philos->meals != philos->table->rules.number_eat)
	{
		if (deadline(philos) == 1)
		{
			printf("%ld %d died | meals = %d\n", get_timestamp(),
				philos->index, philos->meals);
			philos->table->finish = 1;
			return (1);
		}
	}
	return (0);
}

void	*supervisor(void *supervisor)
{
	t_table	*tmp;
	int		i;
	int		meal;

	tmp = (t_table *)supervisor;
	usleep(1000);
	while (1)
	{
		i = 0;
		meal = 0;
		while (i < tmp->rules.philos)
		{
			if (tmp->rules.number_eat != -1 && all_eaten(&tmp->philos[i]))
				meal++;
			if (meal == tmp->rules.philos)
			{
				tmp->finish = 1;
				return (0);
			}
			if (dead_or_alive(&tmp->philos[i]))
				return (0);
			i++;
		}
		usleep(100);
	}
}
