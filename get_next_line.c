/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:25:17 by yourname          #+#    #+#             */
/*   Updated: 2025/03/05 20:39:50 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

static char	*extract_remainder(char *line)
{
	size_t	i;
	char	*leftover;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	leftover = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!leftover)
		return (NULL);
	line[i + 1] = '\0';
	return (leftover);
}

static char	*read_and_append(int fd, char *saved_data)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(saved_data);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = saved_data;
		if (!saved_data)
			saved_data = ft_strdup("");
		saved_data = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (saved_data);
}

char	*get_next_line(int fd)
{
	static char	*saved_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(saved_data);
		saved_data = NULL;
		return (NULL);
	}
	line = read_and_append(fd, saved_data);
	if (!line)
		return (NULL);
	saved_data = extract_remainder(line);
	return (line);
}
