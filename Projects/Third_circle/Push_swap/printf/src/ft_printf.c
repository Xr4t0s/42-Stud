/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:38:21 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 17:01:32 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	character(int c)
{
	if (c > 256 || c < 0)
		c %= 256;
	return (write(1, &c, 1));
}

int	string(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	return (write(1, s, len));
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		flag;
	int		counter;

	i = 0;
	flag = 0;
	va_start (ptr, s);
	counter = 0;
	while (s[i])
	{
		flag = find_flag(s[i + 1]);
		if (s[i] != '%')
		{
			counter++;
			write(1, &s[i++], 1);
		}
		else
		{
			counter += parse(flag, ptr);
			i += 2;
		}
	}
	return (counter);
	va_end(ptr);
}

int	parse(int flag, va_list ptr)
{
	int	count;

	count = 0;
	if (flag == 1)
		count += character(va_arg(ptr, int));
	else if (flag == 2)
		count += string(va_arg(ptr, void *));
	else if (flag == 3)
		count += print_addr(va_arg(ptr, unsigned long long));
	else if (flag == 4 || flag == 5)
		count += ft_putnbr(va_arg(ptr, int));
	else if (flag == 6)
		count += ft_unsigned_putnbr(va_arg(ptr, unsigned int));
	else if (flag == 7)
		count += ft_putnbr_base(va_arg(ptr, int));
	else if (flag == 8)
		count += ft_putnbr_base_maj(va_arg(ptr, int));
	else if (flag == 9)
	{
		write(1, "\%", 1);
		count++;
	}
	return (count);
}

/* int main()
{
	printf("%d\n", ft_printf(" %c ", 'a'));
} */