/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:23:01 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/29 16:05:26 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_H
# define AVLTREE_H
# include "utils.h"
# include <stdlib.h>

typedef struct s_AVLNode
{
	char				*key;
	char				*value;
	struct s_AVLNode	*left;
	struct s_AVLNode	*right;
	int					height;
}						t_AVLNode;

typedef struct s_AVL
{
	t_AVLNode			*root;
	int					size;
}						t_AVL;

// ALV_utils.c
int						get_height(t_AVLNode *node);
t_AVLNode				*create_node(const char *key, const char *value);
int						get_balance_factor(t_AVLNode *node);
int						ft_max(int a, int b);
void					ft_putstr_fd(const char *s, int fd);

// rotate.c
t_AVLNode				*right_rotate(t_AVLNode *y);
t_AVLNode				*left_rotate(t_AVLNode *x);

// insert.c
t_AVLNode				*insert(t_AVLNode *node, const char *key,
							const char *value);

// AVLtree.c
void					destroy_tree(t_AVLNode *node);
t_AVLNode				*search_avl(t_AVLNode *node, const char *key);

#endif // AVLTREE_H
