/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search-map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:00:03 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 15:27:18 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hashmap.h"

int	search(const char *key, void *ctx)
{
	t_map			*map;
	unsigned int	idx;
	t_map_entry		*cur;

	if (!key || !ctx)
		return (-1);
	map = (t_map *)ctx;
	idx = hash_func(key);
	cur = map->entries[idx];
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			if (write(STDOUT_FILENO, cur->value, ft_strlen(cur->value)) < 0)
				return (-1);
			return (0);
		}
		cur = cur->next;
	}
	if (write(STDOUT_FILENO, key, ft_strlen(key) - 1) < 0)
		return (-1);
	if (write(STDOUT_FILENO, ": Not found.\n", 13) < 0)
		return (-1);
	return (0);
}
