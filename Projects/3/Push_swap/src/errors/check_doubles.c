/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:46:59 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:46:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_there_twins(char **args)
{
	int		i;
	int		j;
	long	*x;
	long	*y;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			x = ft_atoi2(args[i]);
			y = ft_atoi2(args[j]);
			if (x[0] == y[0])
				return (free(x), free(y), 1);
			j++;
			free(x);
			free(y);
		}
		i++;
	}
	return (0);
}
