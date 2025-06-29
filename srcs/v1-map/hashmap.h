/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:27:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/29 17:19:47 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
#define HASHMAP_H

#include "utils.h"

#define MAP_SIZE 100000000
#define HASH_ZERO 5381

typedef struct s_map_entry
{
	char *key;
	char *value;
	struct s_map_entry *next;
} t_map_entry;

typedef struct s_map
{
	t_map_entry *entries[MAP_SIZE];
	int count;
} t_map;

#endif