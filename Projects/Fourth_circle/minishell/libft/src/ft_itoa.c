/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:46:50 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/29 15:47:01 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_len_int(int n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		len *= 10;
		n /= 10;
	}
	return (len);
}

static char	*ft_putnbr_char(int n, char *res, int i)
{
	int	len;

	len = ft_len_int(n);
	while (len > 0)
	{
		res[i] = (n / len) + 48;
		i++;
		n %= len;
		len /= 10;
	}
	res[i] = 0;
	return (res);
}

static int	ft_len_char(int n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*res;
	int		i;

	sign = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	res = ft_calloc(((ft_len_char(n) + 1) + sign), 1);
	if (res == NULL)
		return (NULL);
	if (sign == 1)
	{
		res[i] = '-';
		i++;
	}
	res = ft_putnbr_char(n, res, i);
	return (res);
}
