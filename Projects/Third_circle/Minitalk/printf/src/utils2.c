/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:31:05 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/12 18:17:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
