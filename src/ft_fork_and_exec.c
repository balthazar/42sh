/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:24:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/04 13:07:21 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "42sh.h"

static void				st_add_bgjobs(pid_t father)
{
	t_jobs			j;
	int				nb_tmp;
	t_list			*list;

	list = CTX->jobs;
	nb_tmp = 0;
	j.pid = father;
	if (!CTX->jobs)
		j.first = FIRST;
	else if (!CTX->jobs->next)
		j.first = SECOND;
	else
		j.first = LOOSER;
	while (list)
	{
		if (nb_tmp < ((t_jobs *)list->content)->nb)
			nb_tmp = ((t_jobs *)list->content)->nb;
		list = list->next;
	}
	j.nb = nb_tmp + 1;
	ft_lstadd(&CTX->jobs, ft_lstnew(&j, sizeof(t_jobs)));
}

void				ft_fork_and_exec(t_btree *node)
{
	pid_t			father;
	int				status;

	if (-1 == (father = fork()))
		ft_error("fork failed");
	else if (!father)
	{
		if ((signal(SIGTSTP, SIG_DFL) == SIG_ERR))
			ft_error("signal error");
		ft_exec(node);
	}
	waitpid(father, &status, WUNTRACED);
	if (WIFSTOPPED(status))
		st_add_bgjobs(father);
}
