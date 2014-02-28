/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 17:36:24 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					ft_treat_node(t_btree *node)
{
	if (PIPE == C(node)->type)
		ft_pipe(node->left, node->right);
	else if (END == C(node)->type)
	{
		ft_treat_node(node->left);
		ft_treat_node(node->right);
	}
	else if (AND == C(node)->type)
	{
		ft_treat_node(node->left);
		if (!C(node->left)->fail)
			ft_treat_node(node->right);
	}
	else if (CMD == C(node)->type)
	{
		if (ERR == ft_redirect(node) || ERR == ft_fill_path(C(node)))
			C(node)->fail = TRUE;
		else
			ft_fork_and_exec(node);
	}
	return (OK);
}
