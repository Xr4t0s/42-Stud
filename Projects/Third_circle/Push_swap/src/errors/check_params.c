/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:47:26 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:47:26 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ok(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
	{
		if (c == '+')
			return (2);
		else if (c == '-')
			return (-1);
		return (1);
	}
	return (0);
}

int	is_sanitized(char **args)
{
	int		i;
	long	*tmp;

	i = 0;
	while (args[i])
	{
		tmp = ft_atoi2(args[i]);
		if (!tmp)
			return (0);
		if (tmp[0] > 2147483647 || tmp[0] < -2147483648)
			return (0);
		if (tmp[1] == -1)
			return (0);
		i++;
		free(tmp);
	}
	return (1);
}

long	*ft_atoi2(const char *str)
{
	int		i;
	long	mult;
	long	o;
	long	*res;

	res = (long *)malloc(sizeof(long) * 2);
	i = 0;
	mult = 1;
	o = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))
		return (free(res), NULL);
	if (is_ok(str[i]) != 0)
	{
		if (is_ok(str[i]) == -1)
		{
			mult = -1;
			i++;
		}
		else if (is_ok(str[i]) == 2)
			i++;
	}
	else
		return (free(res), NULL);
	if (!ft_isdigit(str[i]))
		return (free(res), NULL);
	while (ft_isdigit(str[i]))
		o = o * 10 + str[i++] - 48;
	res[0] = o * mult;
	if (str[i] == '\0')
		res[1] = 1;
	else
		res[1] = -1;
	return (res);
}
