/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:26:08 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/28 18:16:06 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	configure_rules(char **av, t_table *table)
{
	table->rules.philos = ft_atoi(av[0]);
	table->rules.time_to_die = (time_t)ft_atoi(av[1]);
	table->rules.time_to_eat = (time_t)ft_atoi(av[2]);
	table->rules.time_to_sleep = (time_t)ft_atoi(av[3]);
	if (av[4])
		table->rules.number_eat = (long)ft_atoi(av[4]);
	else
		table->rules.number_eat = -1;
	table->philos = malloc(sizeof(t_philo) * (table->rules.philos + 1));
	if (table->philos == NULL)
		return (1);
	table->forks = malloc(sizeof(*(table->forks)) * (table->rules.philos));
	if (table->forks == NULL)
		return (1);
	return (0);
}

static void	configure_philos(char **av, t_table *table)
{
	int	i;

	i = 0;
	(void)av;
	init_philo(&table);
	if (pthread_create(&table->philos[table->rules.philos].id,
			NULL, supervisor, table) == -1)
		return ;
	pthread_mutex_lock(&table->start);
	while (i < table->rules.philos)
	{
		if (pthread_create(&table->philos[i].id, NULL, threads,
				&table->philos[i]) == -1)
			return ;
		usleep(10);
		i++;
	}
	pthread_mutex_unlock(&table->start);
	while (1)
	{
		pthread_mutex_lock(&table->finish_mutex);
		if (table->finish == 1)
		{
			pthread_mutex_unlock(&table->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->finish_mutex);
		usleep(100);
	}
}

int	configure_table(char **av, t_table *table)
{
	table->finish = 0;
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->start, NULL);
	if (configure_rules(av, table))
		return (ft_return("Malloc Error\n"), 1);
	configure_philos(av, table);
	return (0);
}
