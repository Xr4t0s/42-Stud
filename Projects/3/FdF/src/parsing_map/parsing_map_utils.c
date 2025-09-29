/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:35:07 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/13 18:35:07 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*delete_new_lines(char *xyz)
{
	int		i;
	int		j;
	int		buffer_size;
	char	*ret;

	i = 0;
	j = 0;
	if (!xyz)
		return (NULL);
	buffer_size = ft_strlen(xyz);
	ret = malloc(sizeof(char) * (buffer_size + 1));
	if (!ret)
		ft_return("Error allocating the buffer of delete_new_lines()", 0,
			(void *)0);
	while (xyz[j])
	{
		if (xyz[j] == '\n')
			ret[i++] = ' ';
		else
			ret[i++] = xyz[j];
		j++;
	}
	ret[i] = '\0';
	free(xyz);
	return (ret);
}

int	count_words_in_line(const char *line)
{
	int	words;

	words = 0;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line && *line != '\n')
		{
			words++;
			while (*line && *line != ' ' && *line != '\n')
				line++;
		}
		if (*line == '\n')
			break ;
	}
	return (words);
}

int	count_lines(const char *buffer)
{
	int	i;
	int	count;
	int	words;
	int	first_words;

	i = 0;
	count = 0;
	first_words = -1;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		words = count_words_in_line(&buffer[i]);
		if (first_words == -1)
			first_words = words;
		else if (words != first_words)
			return (-1);
		while (buffer[i] && buffer[i] != '\n')
			i++;
		count++;
		if (buffer[i] == '\n')
			i++;
	}
	return (count);
}

int	count_word(const char *s, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && index == 0)
		{
			index = 1;
			i++;
		}
		else if (*s == c)
			index = 0;
		s++;
	}
	return (i);
}
