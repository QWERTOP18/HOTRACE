/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger-map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:29:00 by ymizukam          #+#    #+#             */
/*   Updated: 2025/06/28 15:48:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

#ifdef DEBUG

void	debug_log(void *ctx)
{
	(void)ctx;
}
#else

void	debug_log(void *ctx)
{
	(void)ctx;
}

#endif