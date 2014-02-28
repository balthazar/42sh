/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/28 10:53:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

int					ft_treat_node(t_btree *node)
{
	if (PIPE == C(node)->type)
		ft_pipe(node->left, node->right);
	else if (CMD == C(node)->type)
	{
		/*
		** 1) redirections
		** 2) recherche de path
		** 3) exec
		*/
		;
	}
	return (OK);
}
