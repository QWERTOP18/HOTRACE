/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:56:43 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 16:06:37 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	*naive_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

static void	ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n < 64)
	{
		naive_memcpy(dest, src, n);
		return ;
	}
	__asm__(
		"1:\n\t"
		"vmovdqu     (%[src]), %%ymm0\n\t"
		"vmovdqu     %%ymm0, (%[dest])\n\t"
		"add         $32, %[src]\n\t"
		"add         $32, %[dest]\n\t"
		"sub         $32, %[count]\n\t"
		"cmp         $32, %[count]\n\t"
		"jge         1b\n\t"
		"2:\n\t"
		"cmp         $0, %[count]\n\t"
		"je          3f\n\t"
		"movsb\n\t"
		"sub         $1, %[count]\n\t"
		"jmp         2b\n\t"
		"3:\n\t"
		: [dest] "+D"(dest), [src] "+S"(src), [count] "+c"(n)
		:
		: "ymm0", "cc", "memory");
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}
