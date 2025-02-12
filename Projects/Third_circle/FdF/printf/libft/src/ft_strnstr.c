/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:38:27 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:38:27 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	index;
	size_t	bckp;

	i = 0;
	index = 0;
	bckp = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while ((char)haystack[i] && i < n)
	{
		if (haystack[i] == needle[index])
		{
			bckp = i;
			while (index < ft_strlen(needle)
				&& haystack[i] == needle[index] && i++ < n)
				index++;
			if (needle[index] == 0)
				return ((char *)&haystack[bckp]);
			index = 0;
			i = bckp;
		}
		i++;
	}
	return (0);
}
