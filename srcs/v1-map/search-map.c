/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search-map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:00:03 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 19:11:52 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hashmap.h"

int	search(const char *key, void *ctx)
{
	t_map			*map;
	unsigned int	idx;
	t_map_entry		*cur;

	map = (t_map *)ctx;
	idx = hash_func(key);
	cur = map->entries[idx];
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			write(STDOUT_FILENO, cur->value, ft_strlen(cur->value));
			return (0);
		}
		cur = cur->next;
	}
	write(STDOUT_FILENO, key, ft_strlen(key) - 1);
	write(STDOUT_FILENO, ": Not found.\n", 14);
	return (0);
}
