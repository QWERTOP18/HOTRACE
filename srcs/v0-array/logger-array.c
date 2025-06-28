/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger-array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:27:31 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 13:52:06 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

#ifdef DEBUG

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
#else

void	debug_log(void *ctx)
{
	(void)ctx;
}
#endif
