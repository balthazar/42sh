/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:27:58 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/01 12:28:06 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

void		if_end(t_btree **tree, t_btree *node)
{
	t_btree	*first;

	first = *tree;
	while (D_NODE == END)
		first = first->right;
	if (first->parent == NULL)
	{
		node->parent = NULL;
		node->left = first;
		first->parent = node;
		*tree = node;
	}
	else
	{
		node->parent = first->parent;
		node->left = first;
		first->parent->right = node;
		first->parent = node;
	}
	node->right = NULL;
}

void		if_or(t_btree **tree, t_btree *node)
{
	t_btree	*first;

	first = *tree;
	while (D_NODE == END || D_NODE == AND || D_NODE == OR)
		first = first->right;
	if (D_NODE == CMD)
	{
		if (first->parent == NULL)
		{
			node->parent = NULL;
			node->left = first;
			first->parent = node;
			*tree = node;
		}
		else
		{
			node->parent = first->parent;
			node->left = first;
			first->parent->right = node;
			first->parent = node;
		}
		node->right = NULL;
	}
}

void		if_pipe(t_btree **tree, t_btree *node)
{
	t_btree	*first;

	first = *tree;
	while (D_NODE == END || D_NODE == AND || D_NODE == OR || D_NODE == PIPE)
		first = first->right;
	if (D_NODE == CMD)
	{
		if (first->parent == NULL)
		{
			node->parent = NULL;
			node->left = first;
			first->parent = node;
			*tree = node;
		}
		else
		{
			node->parent = first->parent;
			node->left = first;
			first->parent->right = node;
			first->parent = node;
		}
		node->right = NULL;
	}
}

void		if_cmd(t_btree **tree, t_btree *node)
{
	t_btree	*first;

	first = *tree;
	while (first->right != NULL)
		first = first->right;
	if (first->left == NULL)
	{
		node->parent = first;
		first->left = node;
	}
	else
	{
		node->parent = first;
		first->right = node;
	}
}

void		if_and(t_btree **tree, t_btree *node)
{
	t_btree	*first;

	first = *tree;
	while (D_NODE == END || D_NODE == AND)
		first = first->right;
	if (first->parent == NULL)
	{
		node->parent = NULL;
		node->left = first;
		first->parent = node;
		*tree = node;
	}
	else
	{
		node->parent = first->parent;
		node->left = first;
		first->parent->right = node;
		first->parent = node;
	}
	node->right = NULL;
}
