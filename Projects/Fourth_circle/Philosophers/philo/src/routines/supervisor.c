/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:05:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/29 00:58:48 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	deadline(t_philo *philo)
{
	long	time;

	time = get_timestamp();
	pthread_mutex_lock(&philo->last_meal_mutex);
	if (time - philo->last_meal > philo->table->rules.time_to_die)
		return (pthread_mutex_unlock(&philo->last_meal_mutex), 1);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (0);
}

static int	all_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->meals >= philo->table->rules.number_eat
		&& philo->table->rules.number_eat != -1)
		return (pthread_mutex_unlock(&philo->meal_mutex), 1);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

static int	dead_or_alive(t_philo *philos)
{
	long	time;

	time = get_timestamp();
	pthread_mutex_lock(&philos->meal_mutex);
	if (philos->meals != philos->table->rules.number_eat)
	{
		if (deadline(philos) == 1)
		{
			pthread_mutex_lock(&philos->table->print);
			printf("%ld %d died\n", time, philos->index + 1);
			pthread_mutex_unlock(&philos->table->print);
			mutex_finish(philos);
			pthread_mutex_unlock(&philos->meal_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philos->meal_mutex);
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
				mutex_finish(&tmp->philos[i]);
				return (0);
			}
			if (dead_or_alive(&tmp->philos[i]))
				return (0);
			i++;
		}
		usleep(100);
	}
}
