/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:27:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/28 20:04:13 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include "utils.h"

# define MAP_SIZE 1000000

typedef struct s_map_entry
{
	char				*key;
	char				*value;
	struct s_map_entry	*next;
}						t_map_entry;

typedef struct s_map
{
	t_map_entry			*entries[MAP_SIZE];
	int					count;
}						t_map;

#endif