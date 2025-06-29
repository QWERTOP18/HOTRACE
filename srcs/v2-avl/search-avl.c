/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search-avl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:00:28 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/29 16:06:41 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

t_AVLNode	*search_avl(t_AVLNode *root, const char *key)
{
	int	cmp;

	if (!root)
		return (NULL);
	cmp = ft_strcmp(key, root->key);
	if (cmp < 0)
		return (search_avl(root->left, key));
	else if (cmp > 0)
		return (search_avl(root->right, key));
	else
		return (root);
}

int	search(const char *key, void *ctx)
{
	t_AVL		*avl_ctx;
	t_AVLNode	*root;
	t_AVLNode	*found;

	if (!key || !ctx)
		return (-1);
	avl_ctx = (t_AVL *)ctx;
	root = avl_ctx->root;
	found = search_avl(root, key);
	if (found)
		ft_putstr_fd(found->value, STDOUT_FILENO);
	else
	{
		if (write(STDOUT_FILENO, key, ft_strlen(key) - 1) < 0)
			return (-1);
		ft_putstr_fd(": Not found.\n", STDOUT_FILENO);
	}
	return (0);
}
