/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:17:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/17 01:01:39 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_table table;

    if (ac != 6)
        return (0);
    if (!configure_table(av++, &table))
        ft_return("Configuration failed, please check your parameters.");
    return (1);
}