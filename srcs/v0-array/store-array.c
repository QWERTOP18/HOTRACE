/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store-array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:01:21 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 14:18:41 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	store(const char *key, const char *value, void *ctx)
{
	const char	***array = (const char ***)ctx;
	static int	i = 0;

	if (!key || !value || !ctx)
		return (-1);
	array[i][0] = ft_strdup(key);
	if (!array[i][0])
		return (-1);
	array[i][1] = ft_strdup(value);
	if (!array[i][1])
		return (-1);
	i++;
	if (i >= 100000)
		return (-1);
	return (0);
}
