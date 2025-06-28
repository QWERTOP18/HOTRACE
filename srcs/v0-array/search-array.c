/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search-array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:16:14 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 13:44:02 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	search(const char *key, void *ctx)
{
	char	***array;
	int		i;

	if (!key || !ctx)
		return (-1);
	array = (char ***)ctx;
	i = 0;
	while (array[i][0] && array[i][1])
	{
		if (ft_strcmp(array[i][0], key) == 0)
		{
			write(STDOUT_FILENO, array[i][1], ft_strlen(array[i][1]));
			return (0);
		}
		i++;
	}
	write(STDOUT_FILENO, key, ft_strlen(key));
	write(STDOUT_FILENO, ": Not found.\n", 14);
	return (0);
}
