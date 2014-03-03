/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/03 13:02:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "42sh.h"

static void				st_child(int *fdes, t_btree *node1)
{
		dup2(fdes[1], 1);
		close(fdes[0]);
		if (CMD == C(node1)->type)
		{
			if (ERR == ft_redirect(node1) || ERR == ft_fill_path(C(node1)))
				C(node1)->fail = TRUE;
			else
				ft_exec(node1);
		}
		else
			ft_treat_node(node1);
		exit(1);
}

static void				st_run_pipe(t_btree *node1, t_btree *node2)
{
	pid_t			father;
	int				fdes[2];

	pipe(fdes);
	if (-1 == (father = fork()))
	{
		close(fdes[0]);
		close(fdes[1]);
		exit(1);
	}
	else if (!father)
		st_child(fdes, node1);
	dup2(fdes[0], 0);
	close(fdes[1]);
	wait(NULL);
	if (CMD == C(node2)->type)
	{
		if (ERR == ft_redirect(node2) || ERR == ft_fill_path(C(node2)))
			C(node2)->fail = TRUE;
		else
			ft_exec(node2);
	}
	else
		ft_treat_node(node2);
}

int						treat_pipe(t_btree *node)
{
	pid_t			father;

	if (-1 == (father = fork()))
		exit(1);
	else if (!father)
	{
		st_run_pipe(node->left, node->right);
		exit(1);
	}
	wait(NULL);
	return (OK);
}
