/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:25:36 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/22 21:56:35 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_params(char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (av[i])
    {
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}
