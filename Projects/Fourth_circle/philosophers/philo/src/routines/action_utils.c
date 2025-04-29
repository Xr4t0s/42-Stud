/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:20:37 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/27 22:20:37 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo **target, char *message)
{
	long	time;

	time = get_timestamp();
	pthread_mutex_lock(&(*target)->table->print);
	printf("%ld %d %s\n", time, (*target)->index + 1, message);
	pthread_mutex_unlock(&(*target)->table->print);
}

void	mutex_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void	mutex_last_meal(t_philo *philo)
{
	long	time;

	time = get_timestamp();
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
}

int	check_finish(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->table->finish_mutex);
	if ((*philo)->table->finish == 1)
	{
		pthread_mutex_unlock(&(*philo)->table->finish_mutex);
		return (0);
	}
	pthread_mutex_unlock(&(*philo)->table->finish_mutex);
	return (1);
}

int	check_finish_and_unlock(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->table->finish_mutex);
	if ((*philo)->table->finish == 1)
	{
		pthread_mutex_unlock((*philo)->l_forks);
		pthread_mutex_unlock((*philo)->r_forks);
		pthread_mutex_unlock(&(*philo)->table->finish_mutex);
		return (0);
	}
	pthread_mutex_unlock(&(*philo)->table->finish_mutex);
	return (1);
}
