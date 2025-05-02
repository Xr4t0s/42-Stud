/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:56:42 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/29 15:48:17 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	find_c(char const f, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (f == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		start;
	int		j;

	start = 0;
	j = 0;
	while (find_c(s1[start], set))
		start++;
	if (s1[start] == 0)
		return (ft_strdup(""));
	i = ft_strlen(s1) - 1;
	while (find_c(s1[i], set))
		i--;
	res = malloc((i + 1 - start) * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	while (start < i + 1)
	{
		res[j] = s1[start];
		start++;
		j++;
	}
	res[j] = 0;
	return (res);
}
