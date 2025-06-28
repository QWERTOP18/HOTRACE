/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:13:45 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/28 19:13:47 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_UTILS_H
# define HASH_UTILS_H

# include "hashmap.h"
# include "utils.h"
# include <stddef.h>

unsigned int	hash_func(const char *key);
t_map_entry		*create_entry(const char *key, const char *value);
void			free_entry_list(t_map_entry *entry);

#endif
