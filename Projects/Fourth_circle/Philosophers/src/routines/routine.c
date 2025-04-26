/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:45:43 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/26 07:35:30 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	last_odd(t_philo **tmp)
{
	if ((*tmp)->table->rules.philos % 2 == 1)
		usleep(((*tmp)->table->rules.time_to_eat - 1) * 1000);
	pthread_mutex_lock(&(*tmp)->forks);
	pthread_mutex_lock(&(*tmp)->table->philos[0].forks);

	printf("%ld Philo %d : is eating : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	(*tmp)->last_meal = get_timestamp();
	
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	
	pthread_mutex_unlock(&(*tmp)->table->philos[0].forks);
	pthread_mutex_unlock(&(*tmp)->forks);

	printf("%ld Philo %d : is sleeping : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	
	usleep((*tmp)->table->rules.time_to_sleep * 1000);

	printf("%ld Philo %d : is thinking : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
}

static void	last_even(t_philo **tmp)
{
	usleep(((*tmp)->table->rules.time_to_eat - 1) * 1000);
	pthread_mutex_lock(&(*tmp)->table->philos[0].forks);
	pthread_mutex_lock(&(*tmp)->forks);

	printf("%ld Philo %d : is eating : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	(*tmp)->last_meal = get_timestamp();
	
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	
	pthread_mutex_unlock(&(*tmp)->forks);
	pthread_mutex_unlock(&(*tmp)->table->philos[0].forks);

	printf("%ld Philo %d : is sleeping : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	
	usleep((*tmp)->table->rules.time_to_sleep * 1000);

	printf("%ld Philo %d : is thinking : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
}

static void	odd(t_philo **tmp)
{
	if ((*tmp)->table->rules.philos % 2 == 1)
		usleep(((*tmp)->table->rules.time_to_eat - 1) * 1000);
	pthread_mutex_lock(&(*tmp)->forks);
	pthread_mutex_lock(&(*tmp)->table->philos[(*tmp)->index + 1].forks);
	
	printf("%ld Philo %d : is eating : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	(*tmp)->last_meal = get_timestamp();
	
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock(&(*tmp)->table->philos[(*tmp)->index + 1].forks);
	pthread_mutex_unlock(&(*tmp)->forks);
	
	printf("%ld Philo %d : is sleeping : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	
	usleep((*tmp)->table->rules.time_to_sleep * 1000);
	
	printf("%ld Philo %d : is thinking : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
}

static void	even(t_philo **tmp)
{
	if ((*tmp)->meals != 0 && (*tmp)->table->rules.philos % 2 == 1)
		usleep(((*tmp)->table->rules.time_to_eat - 1) * 1000);
	pthread_mutex_lock(&(*tmp)->table->philos[(*tmp)->index + 1].forks);
	pthread_mutex_lock(&(*tmp)->forks);

	printf("%ld Philo %d : is eating : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
	(*tmp)->last_meal = get_timestamp();
	
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock(&(*tmp)->forks);
	pthread_mutex_unlock(&(*tmp)->table->philos[(*tmp)->index + 1].forks);

	printf("%ld Philo %d : is sleeping : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);

	usleep((*tmp)->table->rules.time_to_sleep * 1000);

	printf("%ld Philo %d : is thinking : meals %d\n", get_timestamp(), (*tmp)->index + 1, (*tmp)->meals);
}

void *threads(void *philo)
{
	t_philo *tmp;

	tmp = ((t_philo *)philo);
	if (tmp->index % 2 != 0)
		usleep(1000);
	if (tmp->index == tmp->table->rules.philos - 1 && tmp->table->rules.philos % 2 == 1)
		usleep((tmp->table->rules.time_to_eat * 1000) + 1000);
	while(1)
	{
		if (tmp->index == tmp->table->rules.philos - 1 && tmp->index % 2 == 0)
			last_even(&tmp);
		else if (tmp->index == tmp->table->rules.philos - 1 && tmp->index % 2 == 1)
			last_odd(&tmp);
		else if (tmp->index % 2 == 0)
			even(&tmp);
		else if (tmp->index % 2 == 1)
			odd(&tmp);
		if (tmp->meals >= tmp->table->rules.number_eat && tmp->table->rules.number_eat != -1)
			return (0);
		if (tmp->table->finish == 1)
			return (0);
		continue;
	}
	return (0);
}
