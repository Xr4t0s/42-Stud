/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:58:28 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/28 04:58:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    mutex_finish(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->finish_mutex);
    philo->table->finish = 1;
    pthread_mutex_unlock(&philo->table->finish_mutex);
}
