/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:32:40 by nitadros          #+#    #+#             */
/*   Updated: 2025/04/27 22:44:57 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_return(char *message)
{
	printf("%s\n", message);
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	mult;
	int	o;

	i = 0;
	mult = 1;
	o = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))
		return (0);
	if (str[i] == '-')
	{
		mult *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		o = o * 10 + str[i++] - 48;
	return (o * mult);
}

long	get_timestamp(void)
{
	struct timeval	start;
	long			timestamp;

	if (gettimeofday(&start, NULL) == -1)
		ft_return("Echec gettimeofdate()");
	timestamp = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (timestamp);
}
