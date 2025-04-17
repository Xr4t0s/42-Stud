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

static int	count_word(const char *s, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (*s)
	{
		if (*s != c && index == 0)
		{
			index = 1;
			i++;
		}
		else if (*s == c)
			index = 0;
		s++;
	}
	return (i);
}

static char	*dup_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**res;

	i = -1;
	j = 0;
	index = -1;
	res = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!res)
		return (free(res), NULL);
	while ((size_t)++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || (size_t)i == ft_strlen(s)) && index >= 0)
		{
			res[j++] = dup_word(s, index, i);
			if (!res[j - 1])
				return (free_tab(res), NULL);
			index = -1;
		}
	}
	res[j] = 0;
	return (res);
}
