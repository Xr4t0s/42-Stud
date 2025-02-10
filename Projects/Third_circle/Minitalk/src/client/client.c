/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:01 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/10 01:30:40 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

unsigned char	reverse_bits(unsigned char num)
{
    unsigned char	reversed;
    int				bit_count;
	int				i;

	i = 0;
	bit_count = sizeof(num) * 8;
	reversed = 0;
    while (i < bit_count)
	{
        reversed <<= 1;
        if (num & 1)
            reversed |= 1;
        num >>= 1;
		i++;
    }
    return reversed;
}

void send_c(pid_t t, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(t, SIGUSR2);
		else
		 	kill(t, SIGUSR1);
		usleep(100);
		i--;
	}
}

void send_s(pid_t t, const char *str)
{
	while (*str)
	{
		send_c(t, reverse_bits(*str));
		str++;
	}
	send_c(t, reverse_bits('\0'));
}

int main(int ac, char **av)
{
	pid_t t;
	char *message;

	if (ac != 3)
		return (0);
	

	t = ft_atoi(av[1]);
	message = av[2];
	send_s((pid_t)t, message);
}
