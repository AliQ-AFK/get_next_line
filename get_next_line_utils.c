#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *store, char *buffer)
{
	char	*new_store;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (NULL);
	new_store = malloc(ft_strlen(store) + ft_strlen(buffer) + 1);
	if (!new_store)
		return (NULL);
	i = 0;
	if (store)// Copy `store` only if it exists
	{
		while (store[i])
			new_store[i++] = store[i];
		free(store); // Free old store after copying
	}
	j = 0;
	while (buffer[j])
		new_store[i++] = buffer[j++];
	new_store[i] = '\0'; // Null-terminate the string
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

//retrun a string allocated with malloc and delelte the string froimt the static string 

char	*line(const char *store, size_t index)
{
	char	*line;
	int	i;

	i = 0;
	if (index > -1)
	{
		// Allocate memory for the extracted line, including:
		// - `index + 1` for all characters up to and including `\n`
		// - `+1` for the null terminator `\0` to ensure a valid C string
		line = malloc(index + 2);// for the \n and \0
		if (!line)
			return (NULL);
		while (i <= index)// = for copying \n
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
	if (flag == 1) // Free only store
		free(store);
	else if (flag == 2) // Free both store and line
	{
		free(store);
		free(line);
	}
	else if (flag == 3) // Free store, line, and return new_store
	{
		free(store);
		free(line);
		return (new_store);
	}
	return (NULL);
}

char	*update_store(char *store, char *line, size_t index)
{
	char	*new_store;
	size_t	store_len;
	size_t	line_len;
	size_t	i;

	i = 0;
	index++; // As index = '\n'
	line_len = strlen(line);
	store_len = strlen(store);
	if (store_len - line_len <= 0) // Prevents negative malloc sizes
		return (free_helper(1, store, NULL, NULL));
	new_store = malloc(store_len - line_len + 1);
	if (!new_store)
		return (free_helper(2, store, line, NULL));
	while (i < (store_len - line_len))
		new_store[i++] = store[index + i];
	new_store[i] = '\0';
	return (free_helper(3, store, line, new_store));
}
