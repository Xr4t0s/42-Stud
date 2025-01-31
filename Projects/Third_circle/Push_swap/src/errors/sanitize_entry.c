/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:49:59 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:49:59 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**single_entry(char *av)
{
	char	*buffer;
	char	**args;
	char	*tmp;

	buffer = ft_calloc(1, 1);
	tmp = ft_strjoin(buffer, av);
	free(buffer);
	buffer = tmp;
	args = ft_split(buffer, ' ');
	free(buffer);
	return (args);
}

static char	**multi_entry(char **av)
{
	int		i;
	char	*buffer;
	char	**args;
	char	*tmp;

	i = 0;
	buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	while (av[i])
	{
		tmp = ft_strjoin(buffer, av[i++]);
		free(buffer);
		buffer = tmp;
		tmp = ft_strjoin(buffer, " ");
		free(buffer);
		buffer = tmp;
	}
	args = ft_split(buffer, ' ');
	free(buffer);
	return (args);
}

static int	check_entry(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			&& str[i] != ' ')
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_entries(char **str)
{
	while (*str)
	{
		if (!check_entry(*str))
			return (0);
		str++;
	}
	return (1);
}

char	**sanitize_entry(char **av)
{
	char	**args;

	args = NULL;
	if (!check_entries(av))
		return (NULL);
	if (!av[1] && av[0])
		args = single_entry(av[0]);
	else
		args = multi_entry(av);
	if (!args)
		return (NULL);
	if (!is_sanitized(args))
		return (ft_printf("Error\n"), NULL);
	if (is_there_twins(args))
		return (ft_printf("Error\n"), NULL);
	return (args);
}
