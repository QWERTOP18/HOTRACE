/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger-avl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:48:47 by yui               #+#    #+#             */
/*   Updated: 2025/06/29 16:08:58 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"
#include <stdio.h>

void	inorder_traversal(t_AVLNode *node)
{
	if (node)
	{
		inorder_traversal(node->left);
		printf("%s ", node->key);
		if (node->left)
			printf("(L: %s) ", node->left->key);
		else
			printf("(L: NULL) ");
		if (node->right)
			printf("(R: %s) ", node->right->key);
		else
			printf("(R: NULL) ");
		printf("(H: %d) ", node->height);
		printf("\n");
		if (node->value)
			printf("Value: %s\n", node->value);
		else
			printf("Value: NULL\n");
		inorder_traversal(node->right);
	}
}

#ifdef DEBUG

void	debug_log(void *ctx)
{
	t_AVL		*avl_ctx;
	t_AVLNode	*root;

	avl_ctx = (t_AVL *)ctx;
	if (!avl_ctx)
	{
		printf("Context is NULL.\n");
		return ;
	}
	root = avl_ctx->root;
	if (!root)
	{
		printf("Tree is empty.\n");
		return ;
	}
	printf("Inorder Traversal of AVL Tree:\n");
	inorder_traversal(root);
	printf("\n");
}
#else

void	debug_log(void *ctx)
{
	(void)ctx;
}
#endif
