/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:20:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/17 01:04:08 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_rules
{
    long    philos;
    time_t  time_to_die;
    time_t  time_to_eat;
    time_t  time_to_sleep;
    long    number_eat;
} t_rules;

typedef struct s_philo
{
    pthread_t       id;
    pthread_mutex_t forks;
    time_t          last_meal;
    int             meals;
    struct s_philo *next;
} t_philo;

typedef struct s_table
{
    time_t          timestamp_start;
    t_rules         rules;
    t_philo         *philos;
} t_table;





// Initialisation
int         configure_table(char **av, t_table *table);
long        get_timestamp();

int    ft_return(char *message);