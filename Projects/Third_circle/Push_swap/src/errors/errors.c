#include "push_swap.h"

static int	checkEntry(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-') && str[i] != ' ')
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	checkEntries(char **str)
{
	while(*str)
	{
		if (!checkEntry(*str))
			return (0);
		str++;
	}
	return (1);
}

char **sanitizeEntry(char **av)
{
	int i = 0;
	char *buffer;
	char **args;

	
	buffer = ft_strdup("");
	if (!av[1] && av[0])
	{
		if (!checkEntry(av[0]))
			return (free(buffer), free_arg(args), NULL);
		buffer = ft_strjoin(buffer, av[0]);
		args = ft_split(buffer, ' ');
	}
	else
	{
		if (!checkEntries(av))
			return (free(buffer), free_arg(args), NULL);
		while (av[i])
		{
			buffer = ft_strjoin(buffer, av[i++]);
			buffer = ft_strjoin(buffer, " ");
		}
		args = ft_split(buffer, ' ');
	}
	free(buffer);
	return (args);
}
