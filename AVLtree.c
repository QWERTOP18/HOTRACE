/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:38:06 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 15:43:01 by knishiok         ###   ########.fr       */
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
		free(node);
	}
}

t_AVLNode	*insert(t_AVLNode *node, const char *key, const char *value)
{
	int	cmp;

	if (!node)
		return (create_node(key, value));
	cmp = ft_strcmp(key, node->key);
	if (cmp < 0)
		node->left = insert(node->left, key, value);
	else if (cmp > 0)
		node->right = insert(node->right, key, value);
	else
		return (node);
	node->height = 1 + ft_max(get_height(node->left), get_height(node->right));
	return (balanceing_tree(node));
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
