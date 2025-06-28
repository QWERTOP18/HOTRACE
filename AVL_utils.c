/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:36:02 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 15:13:56 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

int	get_height(t_AVLNode *node)
{
	if (!node)
		return (0);
	return (node->height);
}

t_AVLNode	*create_node(const char *key, const char *value)
{
	t_AVLNode	*new_node;

	new_node = (t_AVLNode *)malloc(sizeof(t_AVLNode));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = ft_strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1;
	return (new_node);
}

int	get_balance_factor(t_AVLNode *node)
{
	if (!node)
		return (0);
	return (get_height(node->left) - get_height(node->right));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
	}
}
