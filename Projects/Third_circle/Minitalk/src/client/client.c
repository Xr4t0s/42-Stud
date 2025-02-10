/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:01 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/10 03:22:17 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_global	g_ = {-1, 0, 0};

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
	return (reversed);
}

void	send_c(pid_t t, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(t, SIGUSR2);
		else
			kill(t, SIGUSR1);
		usleep(200);
		i--;
	}
}

void	send_s(pid_t t, const char *str)
{
	while (*str)
	{
		send_c(t, reverse_bits(*str));
		str++;
	}
	send_c(t, reverse_bits('\0'));
}

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static char	buffer[4096];

	context++;
	info++;
	if (sig == SIGUSR1)
		g_.current &= ~(1 << g_.position);
	else if (sig == SIGUSR2)
		g_.current |= (1 << g_.position);
	g_.position++;
	if (g_.position == 8)
	{
		buffer[g_.i] = g_.current;
		if (buffer[g_.i] == '\0')
		{
			ft_printf("%s\n", buffer);
			ft_bzero(buffer, 4096);
			g_.i = -1;
			exit(0);
		}
		g_.i++;
		g_.current = -1;
		g_.position = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t				t;
	char				*message;
	struct sigaction	sa;

	if (ac != 3)
		return (0);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	t = ft_atoi(av[1]);
	message = av[2];
	send_s((pid_t)t, message);
	while (1)
		pause();
}
