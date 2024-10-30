/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:28:58 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 00:28:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointeur;
	size_t			i;

	pointeur = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pointeur[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
