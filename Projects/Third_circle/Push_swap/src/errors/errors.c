#include "push_swap.h"

static int	checkEntry(char *str)
{
	int	i = 0;
	while (str[i])
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
	while (*str)
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
	char *tmp;

	args = NULL;
	buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);

	if (!av[1] && av[0])
	{
		if (!checkEntry(av[0]))
		{
			free(buffer);
			return (NULL);
		}
		tmp = ft_strjoin(buffer, av[0]);
		free(buffer);
		buffer = tmp;
		args = ft_split(buffer, ' ');
	}
	else
	{
		if (!checkEntries(av))
		{
			free(buffer);
			return (NULL);
		}
		while (av[i])
		{
			tmp = ft_strjoin(buffer, av[i++]);
			free(buffer);
			buffer = tmp;

			tmp = ft_strjoin(buffer, " ");
			free(buffer);
			buffer = tmp;
		}
		args = ft_split(buffer, ' ');
	}

	if (!args) // Si `ft_split` échoue
	{
		free(buffer);
		return (NULL);
	}

	free(buffer);
	return (args);
}
