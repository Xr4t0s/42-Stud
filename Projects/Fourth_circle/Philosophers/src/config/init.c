/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:26:08 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 01:16:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long   get_timestamp(void)
{
	struct      timeval start;
	long        timestamp;

	if(gettimeofday(&start, NULL) == -1)
		ft_return("Echec gettimeofdate()");
	timestamp = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (timestamp);
}

static void configure_rules(char **av, t_table *table)
{
	table->rules.philos = ft_atoi(av[0]);
	table->rules.time_to_die = (time_t)ft_atoi(av[1]);
	table->rules.time_to_eat = (time_t)ft_atoi(av[2]);
	table->rules.time_to_sleep = (time_t)ft_atoi(av[3]);
	if (av[4])
		table->rules.number_eat = (long)ft_atoi(av[4]);
	table->philos = malloc(sizeof(t_philo) * table->rules.philos + 1);
	if (table->philos == NULL)
		return ;
}

void *threads(void *philo)
{
	t_philo *tmp;

	tmp = ((t_philo *)philo);
	while(1)
		(void)philo;
	return (0);
}

static void configure_philos(char **av, t_table *table)
{
	int i;
	
	
	i = 0;
	(void)av;
	while (i < table->rules.philos)
	{
		table->philos[i].index = i;
		table->philos[i].table = table;
		table->philos[i].last_meal = 0;
		table->philos[i].meals = 0;
		pthread_mutex_init(&table->philos[i].forks, NULL);
		table->philos[i].dead_or_alive = 0;
		i++;
	}
	if (pthread_create(&table->philos[i + 1].id, NULL, supervisor, &table) == -1)
		return ;
	i = 0;
	while (i < table->rules.philos)
	{
		printf("%d\n", i);
		if (pthread_create(&table->philos[i].id, NULL, threads, &table->philos[i]) == -1)
			return ;
		i++;
	}
	while(!table->finish)
		continue;
	usleep(100000);
}

int configure_table(char **av, t_table *table)
{
	table->finish = 0;
	configure_rules(av, table);
	configure_philos(av, table);
	table->timestamp_start = get_timestamp();
	printf("%ld\n", table->timestamp_start);
	if(table->timestamp_start)
		return (1);
	return (0);
}
