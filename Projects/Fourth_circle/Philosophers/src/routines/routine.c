/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:45:43 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 00:53:14 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void routines(t_philo *philo)
{
    if (philo->index == philo->table->rules.philos - 1 && philo->index % 2 != 0)
    {
		pthread_mutex_lock(&philo->forks);
        pthread_mutex_lock(&philo->table->philos[0].forks);
        usleep(philo->table->rules.time_to_eat * 1000);
        pthread_mutex_unlock(&philo->forks);
        pthread_mutex_unlock(&philo->table->philos[0].forks);
        usleep(philo->table->rules.time_to_sleep * 1000);
    }
    else if (philo->index % 2 == 0)
    {
		pthread_mutex_lock(&philo->forks);
        pthread_mutex_lock(&philo->table->philos[philo->index + 1].forks);
        usleep(philo->table->rules.time_to_eat * 1000);
        pthread_mutex_unlock(&philo->forks);
        pthread_mutex_unlock(&philo->table->philos[philo->index + 1].forks);
        usleep(philo->table->rules.time_to_sleep * 1000);
    }
}
    