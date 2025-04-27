/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:41:46 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/26 23:18:57 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_philo(t_table **table)
{
	int	i;

	i = 0;
	while (i < (*table)->rules.philos)
	{
		pthread_mutex_init(&(*table)->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < (*table)->rules.philos)
	{
		(*table)->philos[i].index = i;
		(*table)->philos[i].table = *table;
		(*table)->philos[i].last_meal = get_timestamp();
		(*table)->philos[i].meals = 0;
		(*table)->philos[i].l_forks = &(*table)->forks[i];
		(*table)->philos[i].r_forks
			= &(*table)->forks[(i + 1) % (*table)->rules.philos];
		i++;
	}
}
