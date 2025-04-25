/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:20:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/25 02:15:43 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_rules
{
    int    philos;
    time_t  time_to_die;
    time_t  time_to_eat;
    time_t  time_to_sleep;
    long    number_eat;
} t_rules;

typedef struct s_philo
{
    int             index;
    pthread_t       id;
    pthread_mutex_t forks;
    time_t          last_meal;
    int             meals;
    struct s_table  *table;
    int             dead_or_alive;
} t_philo;

typedef struct s_table
{
    time_t          timestamp_start;
    t_rules         rules;
    t_philo         *philos;
	int				finish;
} t_table;


// Parsing
int check_params(char **av);


// Initialisation
void	init_philo(t_table **table);
int         configure_table(char **av, t_table *table);
long        get_timestamp();
int			ft_return(char *message);

// Routines 
void	routines(t_philo *philo);
void	*supervisor(void *supervisor);