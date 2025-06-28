/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:13:50 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/28 19:14:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include <stdlib.h>
#include <string.h>

unsigned int	hash_func(const char *key)
{
	unsigned int	hash;
	int				c;

	hash = 5381;
	while (1)
	{
		c = *key++;
		if (!c)
			break ;
		hash = ((hash << 5) + hash) + c;
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
	t_map_entry	*tmp;

	while (entry)
	{
		tmp = entry;
		entry = entry->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
