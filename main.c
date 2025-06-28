/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:00:28 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 15:39:40 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"
#include "get_next_line.h"
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

static void	struct_tree(t_AVLNode **root)
{
	char	*key;
	char	*value;

	while (1)
	{
		key = get_next_line(STDIN_FILENO);
		if (!key || ft_strcmp(key, "\n") == 0)
		{
			free(key);
			break ;
		}
		value = get_next_line(STDIN_FILENO);
		if (!value)
		{
			free(key);
			break ;
		}
		*root = insert(*root, key, value);
		free(key);
		free(value);
	}
}

static void	handle_query(t_AVLNode *node, const char *key)
{
	t_AVLNode	*found;

	found = search(node, key);
	if (found)
		ft_putstr_fd(found->value, STDOUT_FILENO);
	else
	{
		write(STDOUT_FILENO, key, ft_strlen(key) - 1);
		ft_putstr_fd(": Not found.\n", STDOUT_FILENO);
	}
}

int	main(void)
{
	t_AVLNode	*root;
	char		*key;

	root = NULL;
	struct_tree(&root);
	inorder_traversal(root);
	while (1)
	{
		key = get_next_line(STDIN_FILENO);
		if (!key)
			break ;
		if (ft_strcmp(key, "\n") == 0)
		{
			free(key);
			break ;
		}
		handle_query(root, key);
		free(key);
	}
	destroy_tree(root);
	return (0);
}
