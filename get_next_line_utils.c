/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:31:26 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/05 00:57:40 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *store, char *buffer)
{
	char	*new_store;
	int	i;
	int	j;

	if (!buffer)
		return (NULL);
	new_store = malloc(ft_strlen(store) + ft_strlen(buffer) + 1);
	if (!new_store)
		return (NULL);
	i = -1;
	if (store)
	{
		while (store[++i])
			new_store[i] = store[i];
		free(store);
	}
	else
		i = 0;
	j = 0;
	while (buffer[j])
		new_store[i++] = buffer[j++];
	new_store[i] = '\0';
	return (new_store);
}

int	index(const char *store)
{
	int	i;

	i = 0;
	if (!store)
		return (-1);
	while (store[i])
	{
		if (store[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*line(const char *store, size_t index)
{
	char	*line;
	int		i;

	i = 0;
	if (index > -1)
	{
		line = malloc(index + 2);
		if (!line)
			return (NULL);
		while (i <= index)
		{
			line[i] = store[i];
			i++;
		}
		line[i] = '\0';
		return (line);
	}
	return (NULL);
}

void	*free_helper(int flag, char *store, char *line, char *new_store)
{
	if (flag == 1)
		free(store);
	else if (flag == 2)
	{
		free(store);
		free(line);
	}
	else if (flag == 3)
	{
		free(store);
		free(line);
		return (new_store);
	}
	return (NULL);
}
