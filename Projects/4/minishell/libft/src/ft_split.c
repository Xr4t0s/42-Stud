/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:45:37 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/29 15:47:35 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**ft_cw(char const *s, char c)
{
	int		i;
	int		w;
	char	**tab;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			w++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab = (char **)malloc(sizeof(char *) * (w + 1));
	return (tab);
}

static void	ft_f_tab(char *tab, int len, const char *s)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
}

static int	ft_split_next(char const *s, char **res, char c)
{
	int	i;
	int	len;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		while (s[i] != c && s[i] && len > 0)
		{
			res[x] = (char *)malloc((len + 1) * sizeof(char));
			if (res[x] == NULL)
				return (0);
			ft_f_tab(res[x++], len, &s[i]);
			i = i + len;
		}
	}
	res[x] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		v;

	i = 0;
	res = ft_cw(s, c);
	if (res == NULL)
		return (NULL);
	v = ft_split_next(s, res, c);
	if (v == 0)
	{
		while (res[i] != NULL)
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	return (res);
}

// int	main()
// {
// 	char *str = "  Hello  World!  ";
// 	char c = ' ';
// 	int i = 0;

// 	char **tab = ft_split(str, c);
// 	while(tab[i] != NULL)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	printf("%s\n", tab[i]);
// }
