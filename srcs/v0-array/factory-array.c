/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory-array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:01:13 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 18:25:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*new_ctx(void)
{
	char	***ctx;
	int		i;

	ctx = malloc(sizeof(char **) * 100000);
	if (!ctx)
		return (NULL);
	i = 0;
	while (i < 100000)
	{
		ctx[i] = malloc(sizeof(char *) * 2);
		if (!ctx[i])
		{
			while (i > 0)
			{
				free(ctx[i - 1][0]);
				free(ctx[i - 1][1]);
				free(ctx[--i]);
			}
			return (free(ctx), NULL);
		}
		ctx[i][0] = NULL;
		ctx[i][1] = NULL;
		i++;
	}
	return ((void *)ctx);
}

void	free_ctx(void *ctx)
{
	char	***array;
	int		i;

	if (!ctx)
		return ;
	array = (char ***)ctx;
	i = 0;
	while (i < 100000)
	{
		if (array[i])
		{
			if (array[i][0])
				free(array[i][0]);
			if (array[i][1])
				free(array[i][1]);
			free(array[i]);
		}
		i++;
	}
	free(array);
}
