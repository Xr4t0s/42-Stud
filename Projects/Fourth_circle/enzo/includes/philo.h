/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:20:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/27 04:29:12 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

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
    pthread_mutex_t *l_forks;
	pthread_mutex_t *r_forks;
    time_t          last_meal;
    int             meals;
    struct s_table  *table;
} t_philo;

typedef struct s_table
{
    time_t          timestamp_start;
    t_rules         rules;
    t_philo         *philos;
	pthread_mutex_t *forks;
	int				finish;
	pthread_mutex_t start;
	pthread_mutex_t print;
} t_table;


// Parsing
int check_params(char **av);

// Initialisation
void	init_philo(t_table **table);
int		configure_table(char **av, t_table *table);
long	get_timestamp();

//Utils
int		ft_return(char *message);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

// Routines 
void	*supervisor(void *supervisor);
void	*threads(void *philo);

// Action
void	last_odd(t_philo **tmp);
void	last_even(t_philo **tmp);
void	odd(t_philo **tmp);
void	even(t_philo **tmp);

void 	free_table(t_table *table);

#endif