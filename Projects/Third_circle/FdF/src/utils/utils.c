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


static void	copy_line(char *xyz, char *buffer, int i, int j)
{
	if (xyz[j] == '\n')
		buffer[i] = ' ';
	else
		buffer[i] = xyz[j];
}

char	*delete_new_lines(char *xyz)
{
	int		i;
	int		j;
	int		buffer_size;
	char	buffer[200000];
	char	*ret;

	i = 0;
	j = -1;
	if (!xyz)
		return (NULL);
	while (xyz[++j])
	{
		copy_line(xyz, buffer, i, j);
		i++;
	}
	buffer[i] = 0;
	buffer_size = ft_strlen((const char *)buffer);
	ret = malloc(sizeof(char) * buffer_size);
	if (!ret)
		ft_return("Error allocating the buffer of the delete_new_lines() function", 0);
	i = -1;
	while(buffer[++i])
		ret[i] = buffer[i];
	return (ret[i] = 0, ret);
}

int	count_lines(const char *buffer)
{
    int count = 0;
    int i = 0;

    if (!buffer)
        return 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    if (i > 0 && buffer[i - 1] != '\n')
        count++;
    return (count);
}

int	count_word(const char *s, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
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
