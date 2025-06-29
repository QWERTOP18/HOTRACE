/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:05:24 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/29 16:05:52 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	__asm__("vpxor       %%ymm1, %%ymm1, %%ymm1\n\t"
		"mov         %[str_in], %%rdx\n\t"
		"1:\n\t"
		"vmovdqu     (%%rdx), %%ymm0\n\t"
		"vpcmpeqb    %%ymm1, %%ymm0, %%ymm0\n\t"
		"vpmovmskb   %%ymm0, %%eax\n\t"
		"test        %%eax, %%eax\n\t"
		"jnz         2f\n\t"
		"add         $32, %%rdx\n\t"
		"jmp         1b\n\t"
		"2:\n\t"
		"tzcnt       %%eax, %%eax\n\t"
		"add         %%rax, %%rdx\n\t"
		"sub         %[str_in], %%rdx\n\t"
		"mov         %%rdx, %[len_out]\n\t"
		: [len_out] "=r"(len)
		: [str_in] "r"(str)
		: "rax", "rdx", "ymm0", "ymm1", "cc", "memory");
	return (len);
}
