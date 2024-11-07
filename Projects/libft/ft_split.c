/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:09 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:36:09 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_x(char const *str, char c)
{
	int	x;

	x = 0;
	while (str[x] == c)
		x++;
	return (x);
}

static int	count_occurence(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (!*s)
				return (count);
			count++;
		}
		s++;
	}
	return (count + 1);
}

static char	*ft_strdup_bckp(const char *s, char end)
{
	int		i;
	int		x;
	char	*res;

	x = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[x] != end)
		x++;
	res = (char *)malloc(sizeof(char) * (x + 1));
	if (!res)
		return (NULL);
	while (i < x)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		x;
	char	**res;

	j = 0;
	if (!s || !c)
		return (res = malloc(sizeof(char *)), res[0] = NULL, res);
	x = find_x(s, c);
	res = (char **)malloc(sizeof(char *) * (count_occurence(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[x])
	{
		while (s[x] == c)
			x++;
		if (!s[x])
			return (res[j] = 0, res);
		res[j] = ft_strdup_bckp(&s[x], c);
		while (s[x] && s[x] != c)
			x++;
		j++;
	}
	res[j] = 0;
	return (res);
}
