/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:37:23 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:37:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len_s;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!res)
		return (NULL);
	while (i < len_s)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
