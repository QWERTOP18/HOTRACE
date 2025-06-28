/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:00:07 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 19:13:29 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hashmap.h"

int	store(const char *key, const char *value, void *ctx)
{
	t_map			*map;
	unsigned int	idx;
	t_map_entry		*head;
	t_map_entry		*new_entry;

	map = (t_map *)ctx;
	if (!map)
		return (-1);
	idx = hash_func(key);
	head = map->entries[idx];
	new_entry = create_entry(key, value);
	if (!new_entry)
		return (0);
	map->entries[idx] = new_entry;
	new_entry->next = head;
	map->count++;
	return (0);
}
