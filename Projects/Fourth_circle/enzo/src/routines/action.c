/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:07:22 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/27 04:40:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	last_odd(t_philo **tmp)
{
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is thinking\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	pthread_mutex_lock((*tmp)->l_forks);
	pthread_mutex_lock((*tmp)->r_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is eating\n", get_timestamp(), (*tmp)->index);
	(*tmp)->last_meal = get_timestamp();
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock((*tmp)->r_forks);
	pthread_mutex_unlock((*tmp)->l_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is sleeping\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_sleep * 1000);
	if ((*tmp)->table->rules.philos % 2 == 1)
		usleep(((*tmp)->table->rules.time_to_eat) * 1000);
}

void	last_even(t_philo **tmp)
{
	if ((*tmp)->meals == 0)
		usleep(((*tmp)->table->rules.time_to_eat * 1000) + 1000);
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is thinking\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	pthread_mutex_lock((*tmp)->r_forks);
	pthread_mutex_lock((*tmp)->l_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is eating\n", get_timestamp(), (*tmp)->index);
	(*tmp)->last_meal = get_timestamp();
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock((*tmp)->l_forks);
	pthread_mutex_unlock((*tmp)->r_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is sleeping\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_sleep * 1000);
	if ((*tmp)->meals != (*tmp)->table->rules.number_eat)
		usleep(((*tmp)->table->rules.time_to_eat) * 1000);
}

void	odd(t_philo **tmp)
{
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is thinking\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	pthread_mutex_lock((*tmp)->l_forks);
	pthread_mutex_lock((*tmp)->r_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is eating\n", get_timestamp(), (*tmp)->index);
	(*tmp)->last_meal = get_timestamp();
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock((*tmp)->r_forks);
	pthread_mutex_unlock((*tmp)->l_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is sleeping\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_sleep * 1000);
	if ((*tmp)->table->rules.philos % 2 == 1
		&& (*tmp)->meals != (*tmp)->table->rules.number_eat)
		usleep(((*tmp)->table->rules.time_to_eat) * 1000);
}

void	even(t_philo **tmp)
{
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is thinking\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	pthread_mutex_lock((*tmp)->r_forks);
	pthread_mutex_lock((*tmp)->l_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is eating\n", get_timestamp(), (*tmp)->index);
	(*tmp)->last_meal = get_timestamp();
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_eat * 1000);
	(*tmp)->meals++;
	pthread_mutex_unlock((*tmp)->l_forks);
	pthread_mutex_unlock((*tmp)->r_forks);
	if ((*tmp)->table->finish == 1)
		return ;
	pthread_mutex_lock(&(*tmp)->table->print);
	printf("%ld %d is sleeping\n", get_timestamp(), (*tmp)->index);
	pthread_mutex_unlock(&(*tmp)->table->print);
	usleep((*tmp)->table->rules.time_to_sleep * 1000);
	if ((*tmp)->meals != 0 && (*tmp)->table->rules.philos % 2 == 1)
		usleep(((*tmp)->table->rules.time_to_eat) * 1000);
}
