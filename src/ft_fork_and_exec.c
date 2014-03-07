/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_and_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:24:03 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/07 16:37:49 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "42sh.h"

static void				st_deljob(void *content, size_t size)
{
	t_jobs				*job;

	(void)size;
	job = (t_jobs *)content;
	ft_memdel((void **)&job);
}

void					ft_assign_first(t_list *list)
{
	t_list				*ptr;
	t_list				*first;
	t_list				*second;

	if (!list)
		return ;
	else if (!list->next)
	{
		JOB(list)->first = FIRST;
		return ;
	}
	else
	{
		ptr = list;
		first = NULL;
		second = NULL;
		while (ptr)
		{
			if (JOB(ptr)->first == FIRST)
				first = ptr;
			else if (JOB(ptr)->first == SECOND)
				second = ptr;
			ptr = ptr->next;
		}
		if (!first)
		{
			JOB(second)->first = FIRST;
			if (list == second)
				JOB(second->next)->first = SECOND;
			else
				JOB(list)->first = SECOND;
		}
		else if (!second)
		{
			if (list == first)
				JOB(first->next)->first = SECOND;
			else
				JOB(list)->first = SECOND;
		}
	}
}

void					ft_lst_del_job(t_list **list, t_list *node)
{
	t_list				*ptr;
	t_list				*tmp;

	ptr = *list;
	if (node == *list)
	{
		*list = (*list)->next;
		ft_lstdelone(&ptr, st_deljob);
	}
	else
	{
		while (ptr->next)
		{
			if (ptr->next == node)
			{
				tmp = ptr->next;
				ptr->next = ptr->next->next;
				ft_lstdelone(&tmp, st_deljob);
			}
			ptr = ptr->next;
		}
	}
	ft_assign_first(*list);
}

static void				st_add_jobs(pid_t process)
{
	t_jobs			j;
	static int		nb = 1;
	t_list			*list;

	list = CTX->jobs;
	if (!list)
		nb = 1;
	j.pid = process;
	j.first = FIRST;
	while (list)
	{
		if (((t_jobs *)list->content)->first == FIRST)
			((t_jobs *)list->content)->first = SECOND;
		else if(((t_jobs *)list->content)->first == SECOND)
			((t_jobs *)list->content)->first = LOSER;
		list = list->next;
	}
	j.nb = nb;
	nb++;
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
		reset_signal();
		ft_exec(node);
	}
	st_add_jobs(father);
	waitpid(father, &status, WUNTRACED);
	printf("COUCOU\n");
}
