/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:27:17 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 21:27:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmembytes, size_t size)
{
	void	*ptr;
	size_t	total;

	total = 0;
	if (nmembytes == 0 || size == 0)
		return (NULL);
	if (total > 2147483647 / size)
		return (NULL);
	total = nmembytes * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
