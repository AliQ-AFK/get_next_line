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

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	if (store)
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

char	*update_store(char *store, char *line, size_t index)
{
	char *new_store;
	size_t store_len;
	size_t	line_len;
	size_t	i;

	i = 0;
	index ++;//as index = \n	
	line_len = ft_strlen(line); 
	store_len = ft_strlen(store);
	if (store_len - line_len <= 0)//even in edge cases malloc wont alloact neagtives!
	{
		free(store);
		return (NULL);
	}
	// Allocate memory for the remaining part of `store`, excluding the extracted line.
	// - `store_len - line_len` accounts for the remaining characters after `\n`
	// - `+1` ensures space for the null terminator `\0`
	new_store = malloc(store_len - line_len + 1);
	if (!new_store)
	{
		free(store);
		free(line);
		return (NULL);
	}	
	while (i < (store_len - line_len))
	{
		new_store[i] = store[index + i];
		i++;
	}
	new_store[i] = '\0';
	free(store);
	free(line);
	return (new_store);
}
