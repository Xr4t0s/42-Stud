/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:20:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/05 19:46:33 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

typedef struct s_philo
{
    int id;
    int state;
    unsigned long long last_meal;
    long long meals;
    struct s_philo *next;
} t_philo;

typedef struct s_forks
{
    
} t_forks;

typedef struct s_table
{
    t_philo *philos;
    t_forks forks;
} t_table;