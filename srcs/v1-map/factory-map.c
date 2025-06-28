/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory-map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:00:01 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 19:10:55 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_utils.h"
#include "hashmap.h"

void	*new_ctx(void)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->count = 0;
	i = 0;
	while (i < MAP_SIZE)
	{
		map->entries[i++] = NULL;
	}
	return (map);
}

void	free_ctx(void *ctx)
{
	t_map	*map;
	int		i;

	map = (t_map *)ctx;
	if (!map)
		return ;
	i = 0;
	while (i < MAP_SIZE)
	{
		free_entry_list(map->entries[i++]);
	}
	free(map);
}
