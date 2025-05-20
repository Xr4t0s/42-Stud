/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:00:35 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/19 22:21:32 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_exit(char **bin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (bin[1] && bin[1][i])
	{
		if (!ft_isdigit(bin[1][i]))
		{
			printf("numeric argument required\n");
			j++;
		}
		i++;
	}
	if (j && bin[2])
		return (1);
	return (0);
}

int	ft_exit(t_data *data, char **bin)
{
	int	i;

	i = 0;
	printf("exit\n");
	if (!parse_exit(bin) && bin[2])
		return (printf("too many arguments\n"), 0);
	while (data->envp[i])
		free(data->envp[i++]);
	free(data->envp);
	ft_lstclear_m(&data->arg);
	ft_lstclear_c(&data->cmd);
	free(data);
	exit(0);
}
