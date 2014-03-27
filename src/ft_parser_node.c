/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 11:06:17 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/01 12:43:08 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

void		add_node(t_btree **tree, void *data, size_t content_size)
{
	t_btree	*first;
	t_btree	*node;

	first = *tree;
	node = btree_create_node(data, content_size);
	if (!first)
		*tree = node;
	else
	{
		if (D_TREE == PIPE)
			if_pipe(tree, node);
		else if (D_TREE == OR)
			if_or(tree, node);
		else if (D_TREE == END)
			if_end(tree, node);
		else if (D_TREE == AND)
			if_and(tree, node);
		else if (D_TREE == CMD)
			if_cmd(tree, node);
	}
}
