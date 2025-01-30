#include "push_swap.h"

static char **single_entry(char *av)
{
	char *buffer;
	char **args;
	char *tmp;

	buffer = ft_calloc(1, 1);
	tmp = ft_strjoin(buffer, av);
	free(buffer);
	buffer = tmp;
	args = ft_split(buffer, ' ');
	free(buffer);
	return(args);
}

static char **multi_entry(char **av)
{
	int i = 0;
	char *buffer;
	char **args;
	char *tmp;

	buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
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
	free(buffer);
	return (args);
}

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
	char **args;

	args = NULL;
	if (!av[1] && av[0])
	{
		if (!checkEntry(av[0]))
			return (NULL);
		args = single_entry(av[0]);
	}
	else
	{
		if (!checkEntries(av))
			return (NULL);
		args = multi_entry(av);
	}
	if (!args)
		return (NULL);
	return (args);
}

