/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:42:50 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 17:02:25 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

static t_AVLNode	*handle_left_imbalance(t_AVLNode *node)
{
	if (get_balance_factor(node->left) < 0)
	{
		node->left = left_rotate(node->left);
	}
	return (right_rotate(node));
}

static t_AVLNode	*handle_right_imbalance(t_AVLNode *node)
{
	if (get_balance_factor(node->right) > 0)
	{
		node->right = right_rotate(node->right);
	}
	return (left_rotate(node));
}

static t_AVLNode	*balancing_tree(t_AVLNode *node)
{
	int	balance;

	node->height = 1 + ft_max(get_height(node->left), get_height(node->right));
	balance = get_balance_factor(node);
	if (balance > 1)
		return (handle_left_imbalance(node));
	if (balance < -1)
		return (handle_right_imbalance(node));
	return (node);
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
	{
		free(node->value);
		node->value = ft_strdup(value);
		if (!node->value)
		{
			free(node->key);
			free(node);
			return (NULL);
		}
		return (node);
	}
	node->height = 1 + ft_max(get_height(node->left), get_height(node->right));
	return (balancing_tree(node));
}
