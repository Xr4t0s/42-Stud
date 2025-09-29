/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:38:41 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:38:41 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

static char	*ft_strdup_bckp(const char *s, int end)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (!res)
		return (NULL);
	while (i < end)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_findchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_findchr(set, s1[end - 1]))
		end--;
	return (ft_strdup_bckp(&s1[start], end - start));
}
