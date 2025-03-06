/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:10:51 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/06 18:19:40 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

static char	*extract_remainder(char *full_line)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (full_line[i] != '\n' && full_line[i] != '\0')
		i++;
	if (full_line[i] == '\0' || full_line[i + 1] == '\0')
		return (NULL);
	rest = ft_substr(full_line, i + 1, ft_strlen(full_line) - i - 1);
	if (!rest)
		return (NULL);
	full_line[i + 1] = '\0';
	return (rest);
}

static char	*update_remainder(char *remainder, char *buffer)
{
	char	*temp;

	if (!remainder)
		remainder = ft_strdup("");
	temp = remainder;
	remainder = ft_strjoin(temp, buffer);
	free(temp);
	return (remainder);
}

static char	*read_and_store(int fd, char *remainder, char *buffer)
{
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = update_remainder(remainder, buffer);
		if (!remainder || ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*full_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	full_line = read_and_store(fd, remainder, buffer);
	free(buffer);
	if (!full_line)
		return (NULL);
	remainder = extract_remainder(full_line);
	return (full_line);
}
