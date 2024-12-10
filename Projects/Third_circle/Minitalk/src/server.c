#include <bits/types/siginfo_t.h>
#include <signal.h>
#include "../includes/ft_printf.h"

typedef struct {
	unsigned char current;
	unsigned char position;
} Global;

Global g = {0, 0};

void sighandler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		g.current &= ~(1 << g.position);
	else if (sig == SIGUSR2)
		g.current |= (1 << g.position);

	g.position++;
	if (g.position == 8)
	{
		write(1, &g.current, 1);
		g.current = 0;
		g.position = 0;
	}
}

int main()
{
	struct sigaction sa;
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
