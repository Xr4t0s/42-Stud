/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:45:43 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/26 23:20:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	routine(t_philo *tmp)
{
	while (tmp->table->finish != 1)
	{
		if (tmp->meals == tmp->table->rules.number_eat)
		{
			while (tmp->table->finish != 1)
				usleep(100);
			return (1);
		}
		if (tmp->table->finish == 1)
			return (1);
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
	pthread_mutex_lock(&tmp->table->start);
	while (get_timestamp() < tmp->table->timestamp_start + 30)
		usleep(100);
	pthread_mutex_unlock(&tmp->table->start);
	if (tmp->index % 2 != 0)
		usleep(1000);
	if (routine(tmp))
		return (0);
	return (0);
}
