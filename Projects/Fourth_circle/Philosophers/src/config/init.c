/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:26:08 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/17 01:07:27 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long   get_timestamp()
{
    struct      timeval start;
    long        timestamp;

    if(gettimeofday(&start, NULL) == -1)
        ft_return("Echec gettimeofdate()");
    timestamp = (start.tv_sec * 1000) + (start.tv_usec / 1000);
    return (timestamp);
}

int    configure_table(char **av, t_table *table)
{
    av++;
    table->timestamp_start = get_timestamp();
    printf("%ld\n", table->timestamp_start);
    if(table->timestamp_start)
        return (1);
    return (0);
}
