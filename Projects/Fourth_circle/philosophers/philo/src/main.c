/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:17:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/28 22:36:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->rules.philos + 1)
	{
		pthread_join(table->philos[i].id, NULL);
		i++;
	}
	i = 0;
	while (i < table->rules.philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->start);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!(ac == 6 || ac == 5))
		return (0);
	if (!check_params(++av))
	{
		return (ft_return("Invalid params"), 1);
	}
	table.timestamp_start = get_timestamp();
	if (configure_table(av, &table) == 1)
	{
		ft_return("Configuration failed");
		return (0);
	}
	free_table(&table);
	return (1);
}
