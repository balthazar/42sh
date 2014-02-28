/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 14:51:51 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_treat_node(t_btree *node)
{
	if (PIPE == C(node)->type)
		ft_pipe(node->left, node->right);
	else if (CMD == C(node)->type)
	{
		if (ERR == ft_redirect(node) || ERR == ft_fill_path(C(node)))
			C(node)->fail = TRUE;
		else
			ft_fork_and_exec(node);
	}
	return (OK);
}
