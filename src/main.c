/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/27 21:44:59 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

static t_cmd		*st_init_cmd(void)
{
	t_cmd			*cmd;

	if (!(cmd = (t_cmd *) malloc(sizeof(t_cmd))))
		ft_error("Can't malloc 'cmd'");
	cmd->path = NULL;
	cmd->cmd = NULL;
	cmd->env = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->fail = FALSE;
	return (cmd);
}

int					main(void)
{
	t_cmd			*cmd;
	t_btree			*node1;
	t_btree			*node2;
	t_btree			*node3;
	t_btree			*node4;
	t_btree			*node5;

	cmd = st_init_cmd();
	cmd->type = PIPE;
	node1 = btree_create_node(cmd, sizeof(t_cmd));
	node2 = btree_create_node(cmd, sizeof(t_cmd));
	node3 = btree_create_node(ft_make_cmd("/bin/ls",  "ls",  "-l", NULL), sizeof(t_cmd));
	node4 = btree_create_node(ft_make_cmd("/usr/bin/wc",  "wc",  "-l", NULL), sizeof(t_cmd));
	node5 = btree_create_node(ft_make_cmd("/bin/cat",  "cat",  "-e", NULL), sizeof(t_cmd));
	node1->left = node3;
	node1->right = node2;
	node2->left = node4;
	node2->right = node5;
	ft_treat_node(node1);
	return (0);
}
