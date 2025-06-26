/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 06:07:16 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/25 10:00:54 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src)
{
	int		height;
	int		i;
	char	**dest;

	height = 0;
	while (src[height])
		height++;
	dest = malloc(sizeof(char *) * (height + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
