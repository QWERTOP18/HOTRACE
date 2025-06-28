/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:23:01 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 15:43:21 by knishiok         ###   ########.fr       */
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
t_AVLNode				*search(t_AVLNode *node, const char *key);

#endif // AVLTREE_H
