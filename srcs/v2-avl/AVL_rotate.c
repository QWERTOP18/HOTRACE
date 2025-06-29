/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:38:41 by knishiok          #+#    #+#             */
/*   Updated: 2025/06/28 14:58:20 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVLtree.h"

t_AVLNode	*right_rotate(t_AVLNode *y)
{
	t_AVLNode	*x;
	t_AVLNode	*t2;

	x = y->left;
	t2 = x->right;
	x->right = y;
	y->left = t2;
	y->height = 1 + ft_max(get_height(y->left), get_height(y->right));
	x->height = 1 + ft_max(get_height(x->left), get_height(x->right));
	return (x);
}

t_AVLNode	*left_rotate(t_AVLNode *x)
{
	t_AVLNode	*y;
	t_AVLNode	*t2;

	y = x->right;
	t2 = y->left;
	y->left = x;
	x->right = t2;
	x->height = 1 + ft_max(get_height(x->left), get_height(x->right));
	y->height = 1 + ft_max(get_height(y->left), get_height(y->right));
	return (y);
}
