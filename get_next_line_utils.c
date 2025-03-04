#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *store, char *buffer)
{
	char	*new_store;
	size_t	i;
	size_t	j;

	if (!store || !buffer)
		return (NULL);
	i = 0;
	j = 0;
	new_store = malloc(ft_strlen(store) + ft_strlen(buffer) + 1);
	if (!new_store)
		return (NULL);
	while (store[i])
	{
		new_store[i] = store[i];
		i++;
	}
	while (buffer[j])
	{
		new_store[i + j] = buffer[j];
		j++;
	}
	new_store[i + j] = '\0';
	free (store);
	return (new_store);
}

size_t 	index(const char *store)
{
	size_t	i;

	i = 0;
	if (!store)
		return (NULL);
	while (store[i])
	{
		if (store[i] == '\n')
			return (i);
		i++;
	}
	else
		return (-1);
}

//retrun a string allocated with malloc and delelte the string froimt the static string 

char	*line(const char *store, size_t index)
{
	const char	*line;
	size_t	i;

	if (index > -1)
	{
		i = 0;
		line = malloc(index + 1);// the index of the \n already allocats the null termiantor hello\0 = 6 bytes, counting hello\n is 5 so we need + 1
		while (i < index)
		{
			line[i] = store[i];
			i++:
		}
		line[index] = '\0';
		return (line);
	}
	else
		return (NULL);
}

char	*remove(const char *store, const char *line, size_t index)
{
	const char *new_store;

	size_t store_len;
	size_t	line_len;
	size_t	i;

	i = 0;
	index ++;//as index = \n	
	line_len = ft_strlen(line); 
	store_len = ft_strlen(store);
	new_store = malloc(store_len - line_len);// the \n allocates space for the \0	
	while (i < (store_len - line_len))//hello= 5, hello\nWorld! = 12; 12 - 5 = 7 -> World!\0
	{
		remove[i] = store[index + i];
		i++;
	}
	remove[i + index] = '\0';
	free(line);
	free(store);
	return (remove):
}

