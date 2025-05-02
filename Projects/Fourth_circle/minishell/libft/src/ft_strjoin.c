/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:04:38 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/29 15:47:49 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;

	res = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char), 1);
	if (res == NULL)
		return (NULL);
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, (ft_strlen(res) + ft_strlen(s2)) + 1);
	return (res);
}
