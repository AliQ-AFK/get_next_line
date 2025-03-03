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
	new_store = malloc(ft_strlen(store) + ft_strlen(buffer));
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