/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store-array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:01:21 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 00:38:34 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifdef ARRAY
#include <utils.h>

int	store(const char *key, const char *value, void *ctx)
{
	const char	***array = (const char ***)ctx;
	int			i;

	if (!key || !value || !ctx)
		return (-1);
	write(STDOUT_FILENO, "DEBUG: store called: ", 21);
	write(STDOUT_FILENO, key, ft_strlen(key));
	i = 0;
	while (i < 1024)
	{
		if (!array[i][0])
		{
			array[i][0] = ft_strdup(key);
			if (!array[i][0])
				return (-1);
			array[i][1] = ft_strdup(value);
			if (!array[i][1])
				return (-1);
			write(STDOUT_FILENO, " -> stored successfully.\n", 25);
			return (0);
		}
		i++;
	}
	return (-1);
}

// #endif