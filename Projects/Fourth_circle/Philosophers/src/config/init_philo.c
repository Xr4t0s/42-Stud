/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:41:46 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 05:09:22 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_philo(t_table **table)
{
	int	i;

	i = 0;
	while (i < (*table)->rules.philos)
	{
		(*table)->philos[i].index = i;
		(*table)->philos[i].table = *table;
		(*table)->philos[i].last_meal = get_timestamp();
		(*table)->philos[i].meals = 0;
		pthread_mutex_init(&(*table)->philos[i].forks, NULL);
		(*table)->philos[i].dead_or_alive = 0;
		i++;
	}
}
