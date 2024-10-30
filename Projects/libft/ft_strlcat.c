/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:17:09 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 18:17:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	len_dest;
	int		len_src;

	i = 0;
	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] && len_dest < size)
		len_dest++;
	while (src[len_src])
		len_src++;
	if (len_dest == size)
		return (size + len_src);
	while (i < len_src && (len_dest + i) < (size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_dest + len_src);
}
