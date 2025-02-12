/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:08:49 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 16:36:03 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_addr(unsigned long long addr)
{
	int	len;

	len = 0;
	while (addr != 0)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

static void	write_addr(unsigned long long addr)
{
	if (addr >= 16)
	{
		write_addr(addr / 16);
		write_addr(addr % 16);
	}
	else
	{
		if (addr <= 9)
			ft_putchar(addr + 48);
		else
			ft_putchar(addr - 10 + 'a');
	}
}

int	print_addr(unsigned long long addr)
{
	int	len;

	len = 0;
	if (!addr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += write(1, "0x", 2);
	write_addr(addr);
	len += len_addr(addr);
	return (len);
}
