/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:34:11 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:34:11 by nitadros         ###   ########.fr       */
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
