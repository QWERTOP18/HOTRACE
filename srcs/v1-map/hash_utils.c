/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:13:50 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/28 19:51:27 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include <stdlib.h>
#include <string.h>

unsigned int	hash_func(const char *key)
{
	unsigned int	hash;
	int				l;

	l = 0;
	hash = 5381;
	while (key[l])
	{
		hash = ((hash << 5) + hash) + key[l];
		l++;
	}
	return (hash % MAP_SIZE);
}

t_map_entry	*create_entry(const char *key, const char *value)
{
	t_map_entry	*entry;

	entry = malloc(sizeof(t_map_entry));
	if (!entry)
		return (NULL);
	entry->key = ft_strdup(key);
	entry->value = ft_strdup(value);
	entry->next = NULL;
	return (entry);
}

void	free_entry_list(t_map_entry *entry)
{
	t_map_entry	*next_entry;

	while (entry)
	{
		next_entry = entry->next;
		free(entry->key);
		free(entry->value);
		free(entry);
		entry = next_entry;
	}
}
