/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:05:47 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 00:44:44 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_state	process(const char *key, const t_state state, void *ctx)
{
	char	*value;

	if (state == STORE)
	{
		value = parse(STDIN_FILENO);
		if (!value)
			return (EXIT);
		if (store(key, value, ctx))
		{
			free(value);
			return (EXIT);
		}
		free(value);
	}
	else if (state == SEARCH)
	{
		if (search(key, ctx))
		{
			return (EXIT);
		}
	}
	return ((t_state)state);
}

int	main(void)
{
	char	*line;
	void	*ctx;
	t_state	state;

	ctx = new_ctx();
	if (!ctx)
		return (1);
	state = STORE;
	while (state != EXIT)
	{
		line = parse(STDIN_FILENO);
		if (!line)
			break ;
		else if (state == STORE && line[0] == '\n')
		{
			state = SEARCH;
			debug_log(ctx);
		}
		else
			state = process(line, state, ctx);
		free(line);
	}
	free_ctx(ctx);
	return (0);
}
