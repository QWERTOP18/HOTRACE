/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:06:21 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/29 20:57:07 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef ASM

# include "utils.h"

static t_avx_state	ft_strcmp_avx_loop(const char *s1, const char *s2)
{
	t_avx_state	state;

	__asm__("vpxor      %%ymm2, %%ymm2, %%ymm2\n"
			"1:\n"
			"vmovdqu    (%[s1]), %%ymm0\n"
			"vmovdqu    (%[s2]), %%ymm1\n"
			"vpcmpeqb   %%ymm0, %%ymm1, %%ymm3\n"
			"vpcmpeqb   %%ymm0, %%ymm2, %%ymm0\n"
			"vpmovmskb  %%ymm3, %%eax\n"
			"vpmovmskb  %%ymm0, %%edx\n"
			"cmp        $0xffffffff, %%eax\n"
			"jne        2f\n"
			"test       %%edx, %%edx\n"
			"jnz        2f\n"
			"add        $32, %[s1]\n"
			"add        $32, %[s2]\n"
			"jmp        1b\n"
			"2:\n"
			: "=a"(state.mask_neq), "=d"(state.mask_null_s1), [s1] "+r"(s1),
				[s2] "+r"(s2)
			:
			: "ymm0", "ymm1", "ymm2", "ymm3", "cc", "memory");
	state.s1 = s1;
	state.s2 = s2;
	return (state);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	t_avx_state	state;
	int			result;

	state = ft_strcmp_avx_loop(s1, s2);
	__asm__("vpxor      %%ymm2, %%ymm2, %%ymm2\n"
			"xor        $0xffffffff, %[mask_neq]\n"
			"vmovdqu    (%[s2]), %%ymm1\n"
			"vpcmpeqb   %%ymm1, %%ymm2, %%ymm1\n"
			"vpmovmskb  %%ymm1, %%ecx\n"
			"or         %%ecx, %[mask_null_s1]\n"
			"or         %[mask_null_s1], %[mask_neq]\n"
			"tzcnt      %%rax, %%rax\n"
			"movzbl     (%[s1], %%rax), %%ecx\n"
			"movzbl     (%[s2], %%rax), %%edx\n"
			"sub        %%edx, %%ecx\n"
			: "=c"(result)
			: [s1] "D"(state.s1), [s2] "S"(state.s2),
				[mask_neq] "a"(state.mask_neq),
				[mask_null_s1] "d"(state.mask_null_s1)
			: "ymm1", "ymm2", "cc", "memory");
	return (result);
}
#endif