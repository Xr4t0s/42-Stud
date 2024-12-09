#include "get_next_line.h"
#include <fcntl.h>

char	*get_good_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), (ft_strlen(buffer) - i + 1));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*free_buff(char *ret, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(ret, buffer);
	free(ret);
	return (tmp);
}

char	*get_good_line(char *line)
{
	char	*ret;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	ret = ft_calloc(sizeof(char), (i + 2));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		ret[i++] = '\n';
	return (ret);
}

char	*read_lines(int fd, char *buffer)
{
	char	*ret;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	ret = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, ret, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(ret), NULL);
		ret[bytes_read] = 0;
		buffer = free_buff(buffer, ret);
		if (ft_strchr(ret, '\n'))
			break ;
	}
	free(ret);
	if (!buffer)
		return (NULL);
	if (!buffer[0])
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = read_lines(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_good_line(buffer);
	buffer = get_good_next(buffer);
	return (line);
}

/*
int main()
{
	int fd;
	int i = -1;

	fd = open("get_next_line.h", O_RDONLY);
	while (1)
	{
		char *line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
		else
			break ;
	}
}*/
