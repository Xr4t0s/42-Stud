/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:45:43 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/28 03:48:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	routine(t_philo *tmp)
{
	while (1)
	{
		pthread_mutex_lock(&tmp->table->finish_mutex);
		if (tmp->table->finish == 1)
		{
			pthread_mutex_unlock(&tmp->table->finish_mutex);
			return (1);
		}
		pthread_mutex_unlock(&tmp->table->finish_mutex);

		pthread_mutex_lock(&tmp->meal_mutex);
		if (tmp->meals == tmp->table->rules.number_eat)
		{
			pthread_mutex_unlock(&tmp->meal_mutex);
			while (1)
			{
				pthread_mutex_lock(&tmp->table->finish_mutex);
				if (tmp->table->finish == 1)
				{
					pthread_mutex_unlock(&tmp->table->finish_mutex);
					return (1);
				}
				pthread_mutex_unlock(&tmp->table->finish_mutex);
				usleep(100);
			}
		}
		pthread_mutex_unlock(&tmp->meal_mutex);

		if (tmp->index == (tmp->table->rules.philos - 1) && tmp->index % 2 == 0)
			last_even(&tmp);
		else if (tmp->index == (tmp->table->rules.philos - 1)
			&& tmp->index % 2 == 1)
			last_odd(&tmp);
		else if (tmp->index % 2 == 0)
			even(&tmp);
		else if (tmp->index % 2 == 1)
			odd(&tmp);
	}
	return (0);
}

void	*threads(void *philo)
{
	t_philo	*tmp;

	tmp = ((t_philo *)philo);
	if (tmp->index % 2 != 0)
		usleep(1000);
	routine(tmp);
	return (NULL);
}
