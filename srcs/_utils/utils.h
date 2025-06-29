/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:53:45 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 20:58:46 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_avx_state
{
	const char	*s1;
	const char	*s2;
	int			mask_neq;
	int			mask_null_s1;
}				t_avx_state;

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);

#endif