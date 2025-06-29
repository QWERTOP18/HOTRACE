/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory-avl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:55:03 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 16:03:01 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

void	*new_ctx(void)
{
	t_AVL	*ctx;

	ctx = (t_AVL *)malloc(sizeof(t_AVL));
	if (!ctx)
		return (NULL);
	ctx->root = NULL;
	ctx->size = 0;
	return (ctx);
}

void	destroy_tree(t_AVLNode *node)
{
	if (node)
	{
		destroy_tree(node->left);
		destroy_tree(node->right);
		free(node->key);
		free(node->value);
		free(node);
	}
}

void	free_ctx(void *ctx)
{
	t_AVL	*avl_ctx;

	if (!ctx)
		return ;
	avl_ctx = (t_AVL *)ctx;
	destroy_tree(avl_ctx->root);
	free(avl_ctx);
}
