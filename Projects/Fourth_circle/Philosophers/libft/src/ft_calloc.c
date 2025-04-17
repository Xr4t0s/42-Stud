/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:01 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/04 13:29:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmembytes, size_t size)
{
	void	*ptr;
	size_t	total;

	total = 0;
	if (nmembytes == 0 || size == 0)
		return (ptr = malloc(0), ptr);
	if (total > 2147483647 / size)
		return (NULL);
	total = nmembytes * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
