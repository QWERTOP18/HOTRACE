/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger-array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:27:31 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 18:25:50 by ymizukam         ###   ########.fr       */
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
	while (i < 100000 && array[i][0])
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
