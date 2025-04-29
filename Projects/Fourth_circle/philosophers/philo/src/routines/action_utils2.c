/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:58:28 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/28 17:27:03 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->finish_mutex);
	philo->table->finish = 1;
	pthread_mutex_unlock(&philo->table->finish_mutex);
}

int	check_solo(t_philo **tmp)
{
	if ((*tmp)->table->rules.philos <= 1)
	{
		pthread_mutex_unlock((*tmp)->l_forks);
		pthread_mutex_unlock(&(*tmp)->table->finish_mutex);
		(*tmp)->table->finish = 1;
		return (0);
	}
	return (1);
}
