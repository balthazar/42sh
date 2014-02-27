/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/02/27 20:48:15 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

static void			st_run_pipe(t_btree *node1, t_btree *node2)
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
	{
		dup2(fdes[1], 1);
		close(fdes[0]);
		execve(C(node1)->path, C(node1)->cmd, C(node1)->env);
		exit(1);
	}
	dup2(fdes[0], 0);
	close(fdes[1]);
	wait(NULL);
	execve(C(node2)->path, C(node2)->cmd, C(node2)->env);
}

int					ft_pipe(t_btree *node1, t_btree *node2)
{
	pid_t			father;

	if (-1 == (father = fork()))
		exit(1);
	else if (!father)
	{
		st_run_pipe(node1, node2);
		exit(1);
	}
	wait(NULL);
	return (0);
}
