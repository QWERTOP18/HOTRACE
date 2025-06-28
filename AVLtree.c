/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:38:06 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 16:51:08 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

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

t_AVLNode	*search(t_AVLNode *root, const char *key)
{
	int	cmp;

	if (!root)
		return (NULL);
	cmp = ft_strcmp(key, root->key);
	if (cmp < 0)
		return (search(root->left, key));
	else if (cmp > 0)
		return (search(root->right, key));
	else
		return (root);
}
