#include <signal.h>
#include <unistd.h>
#include "../includes/ft_printf.h"

unsigned char reverse_bits(unsigned char num) {
    unsigned char reversed = 0;
    int bit_count = sizeof(num) * 8;  // Pour un char, c'est généralement 8 bits

    for (int i = 0; i < bit_count; i++) {
        reversed <<= 1;  // Décale 'reversed' vers la gauche pour libérer de la place
        if (num & 1) {  // Si le bit de droite de 'num' est 1
            reversed |= 1;  // Met le bit de droite de 'reversed' à 1
        }
        num >>= 1;  // Décale 'num' vers la droite pour analyser le bit suivant
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
		i--;
		usleep(50);
	}
	usleep(200);
}

void send_s(pid_t t, const char *str)
{
	while(*str)
	{
		send_c(t, reverse_bits(*str));
		str++;
	}
	send_c(t, reverse_bits('\0'));
}

int main()
{
	pid_t t;
	char *message = "Hello from clieeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeent\n";

	printf("Entrez le pid : ");
	scanf("%d", &t);
	send_s(t, message);
	
}
