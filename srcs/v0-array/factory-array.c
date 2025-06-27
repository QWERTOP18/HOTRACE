/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory-array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 00:01:13 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 00:40:44 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*new_ctx(void)
{
	char	***ctx;
	int		i;

	ctx = malloc(sizeof(char **) * 1024);
	if (!ctx)
		return (NULL);
	i = 0;
	while (i < 1024)
	{
		ctx[i] = malloc(sizeof(char *) * 2);
		if (!ctx[i])
		{
			while (i > 0)
			{
				free(ctx[i - 1][0]);
				free(ctx[i - 1][1]);
				free(ctx[i - 1]);
				i--;
			}
			free(ctx);
			return (NULL);
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
	while (i < 1024)
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

void	debug_log(void *ctx)
{
	char	***array;
	int		i;

	if (!ctx)
		return ;
	array = (char ***)ctx;
	i = 0;
	while (i < 1024 && array[i][0])
	{
		write(STDOUT_FILENO, array[i][0], ft_strlen(array[i][0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, array[i][1], ft_strlen(array[i][1]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
