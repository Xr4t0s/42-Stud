/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:31:11 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:28:25 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strchr1(const char *s, int c)
{
	int	i;
	int	limit;

	i = 0;
	limit = ft_strlen(s) + 1;
	while (i < limit)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static void	loop_rm_char(t_rm_char *rm, char *str, char *ch)
{
	while (str[rm->i])
	{
		if (!ft_strchr1(ch, str[rm->i]))
			rm->ret[rm->x++] = str[rm->i];
		else
		{
			if (rm->mark == 1)
			{
				rm->ret[rm->x++] = ';';
				rm->mark = 0;
			}
			while (str[rm->i] && ft_strchr1(ch, str[rm->i]))
				rm->i++;
			continue ;
		}
		rm->i++;
	}
}

char	*ft_rm_char(char *str, char *ch)
{
	t_rm_char	rm;

	rm.mark = 1;
	rm.i = 0;
	rm.x = 0;
	if (!str || !ch)
		return (NULL);
	rm.ret = calloc(8, ft_strlen(str) + 1);
	if (!rm.ret)
		return (NULL);
	while (str[rm.i] && ft_strchr1(ch, str[rm.i]))
		rm.i++;
	loop_rm_char(&rm, str, ch);
	rm.ret[rm.x] = 0;
	free(str);
	return (rm.ret);
}
