/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqeblawi <aqeblawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:38:48 by aqeblawi          #+#    #+#             */
/*   Updated: 2025/03/05 00:58:59 by aqeblawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_store(char *store, char *line, size_t index)
{
	char	*new_store; 
	size_t	store_len;
	size_t	line_len;
	size_t	i;

	i = 0;
	index++;
	line_len = strlen(line);
	store_len = strlen(store);
	if (store_len - line_len <= 0)
		return (free_helper(1, store, NULL, NULL));
	new_store = malloc(store_len - line_len + 1);
	if (!new_store)
		return (free_helper(2, store, line, NULL));
	while (i < (store_len - line_len))
		new_store[i++] = store[index + i];
	new_store[i] = '\0';
	return (free_helper(3, store, line, new_store));
}
