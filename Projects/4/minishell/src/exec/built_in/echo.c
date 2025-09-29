/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:57:09 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/04 04:55:06 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **arg)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (arg[1] && !ft_strcmp(arg[1], "-n"))
	{
		newline = 0;
		i++;
	}
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (1);
}
