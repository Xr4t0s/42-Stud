/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:13:05 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/06 00:01:18 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/siginfo_t.h>
#include <signal.h>
#include "../includes/ft_printf.h"
#include "minitalk.h"

Global	g = {-1, 0, 0};

void sighandler(int sig, siginfo_t *info, void *context)
{
	static char buffer[4096];

	if (sig == SIGUSR1)
		g.current &= ~(1 << g.position);
	else if (sig == SIGUSR2)
		g.current |= (1 << g.position);

	g.position++;
	
	if (g.position == 8)
	{
		buffer[g.i] = g.current;
		if (buffer[g.i] == '\0')
		{
			ft_printf("%s\n", buffer);
			ft_bzero(buffer, 4096);
			g.i = -1;
		}
		g.i++;
		g.current = -1;
		g.position = 0;
	}
}

int main()
{
	struct sigaction	sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("Waiting for signals... PID : %d\n", getpid());
	while(1)
		pause();
	return (0);
}
