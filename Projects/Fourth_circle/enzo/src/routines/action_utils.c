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
	printf("%ld %d %s\n", time, (*target)->index, message);
	pthread_mutex_unlock(&(*target)->table->print);
}

