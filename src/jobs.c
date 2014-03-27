/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:16:36 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/11 14:19:07 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include "norme42sh.h"

void				ft_ctrl_c(int i)
{
	int				ret;

	(void)i;
	if (CTX->jobs && CTX->sub_proc)
	{
		ret = kill(((t_jobs *)CTX->jobs->content)->pid, SIGKILL);
		if (ret == -1)
			ft_error("signal error");
		else
		{
			CTX->sub_proc = 0;
			ft_putchar('\n');
			CTX->prompt = 0;
			ft_clear_line();
			ft_aff_prompt();
		}
	}
	else
	{
		ft_putchar('\n');
		CTX->prompt = 0;
		ft_clear_line();
		ft_aff_prompt();
	}
}

void				ft_ctrlz(int sig)
{
	(void)sig;
	if (CTX->jobs && CTX->sub_proc)
	{
		ft_raw_term();
		ft_putchar('\n');
		ft_putstr("[1]+  Stopped(SIGTSTP) ");
		ft_putendl(JOB(CTX->jobs)->line);
		CTX->sub_proc = 0;
		CTX->prompt = 0;
		ft_clear_line();
		ft_aff_prompt();
	}
}

void				ft_child(int sig)
{
	t_list			*ptr;
	int				status;

	(void)sig;
	ptr = CTX->jobs;
	while (ptr)
	{
		if (waitpid(JOB(ptr)->pid, &status, WNOHANG) != 0)
		{
			if (!WIFSTOPPED(status))
			{
				ft_raw_term();
				ft_lst_del_job(&(CTX->jobs), ptr);
				CTX->sub_proc = 0;
			}
		}
		ptr = ptr->next;
	}
}

void				ft_fg(int i)
{
	int				status;

	(void)i;
	if (CTX->jobs)
	{
		signal(SIGCONT, SIG_DFL);
		ft_putendl(JOB(CTX->jobs)->line);
		if (kill(((t_jobs *)CTX->jobs->content)->pid, SIGCONT) == -1)
			ft_error("signal error");
		else
		{
			CTX->sub_proc = 1;
			waitpid(JOB(CTX->jobs)->pid, &status, WUNTRACED);
		}
	}
	else
		ft_putendl("fg: current: no such job");
}
