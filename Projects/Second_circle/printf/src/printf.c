/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:38:21 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/15 20:36:36 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	t_flags *flags;
	int	i;

	i = 0;
	flags = init();
	va_start (ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
		if (parsing(s[i]) == 0)
			i++;
		
	}
	return (va_arg(ptr, char *));
	va_end(ptr);
}
int main()
{
	printf("%-+3d", -1);
}