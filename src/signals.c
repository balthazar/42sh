/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:04:43 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/07 12:45:00 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "42sh.h"

// TODO Manage SIGSTOP and SIGCONT properly
// TODO NORM : 6 functions
/*
static void			ft_nothing(int sig)
{
	(void)sig;
}
*/

void				ft_ctrlz(int sig)
{
	(void)sig;
	printf("IN FT_CRTL_Z\n");
/*	if (CTX->jobs)
	{
		printf("IM HERE LOLS\n");
		signal(SIGTSTP, SIG_DFL);
		if (kill(((t_jobs *)CTX->jobs->content)->pid, SIGTSTP) != -1)
		{
			ft_putendl("[1]+  Stopped(SIGTSTP)\n");
			CTX->prompt = 0;
			ft_clear_line();
			ft_aff_prompt();
		}
		signal(SIGTSTP, ft_ctrlz);
	}*/
}

void				ft_child(int sig)
{
	t_list			*ptr;
	int				status;

	(void)sig;
	ft_putendl("SIGCHILD");
	ptr = CTX->jobs;
	while (ptr)
	{
		if (waitpid(JOB(ptr)->pid, &status, WNOHANG) != 0)
		{
			if (WIFSTOPPED(status))
			{
				printf("PID OF THIS PROCESS %d\n", getpid() );
				printf("STOPPED\n");
			}
			else
			{
				printf("ok %d is finished\n",JOB(ptr)->pid );
				ft_lst_del_job(&(CTX->jobs), ptr);
			}
		}
		ptr = ptr->next;
	}
}

void				ft_fg(int i)
{
	(void)i;
	if (CTX->jobs)
	{
		signal(SIGCONT, SIG_DFL);
		if (kill(((t_jobs *)CTX->jobs->content)->pid, SIGCONT) == -1)
			CTX->prompt = 0;
		else
		{
			//	DELETE element de la liste
			ft_putendl("1fg: current: no such job");
		}
	}
	else
		ft_putendl("2fg: current: no such job");
}

static void			ft_ctrl_c(int i)
{
	pid_t			cool;
	int				ret;

	cool = getpid();
	(void)i;
	dprintf(2, "COOL = %d\n", cool);
	signal(SIGINT, SIG_DFL);
	if (CTX->father == cool)
	{
		if (CTX->jobs)
		{
			printf("sending kill to JOB %d\n", JOB(CTX->jobs)->pid );
			ret = kill(((t_jobs *)CTX->jobs->content)->pid, SIGKILL);
			printf("ret %d\n",ret );
			if (ret == -1)
			{
				ft_putendl("ctrl c n'a pas marche");
			}
			else
			{
				//	DELETE element de la liste
				printf("CTR C MARCHE\n");
				CTX->prompt = 0;
			}
		}
		else
		{
			ft_putchar('\n');
			CTX->prompt = 0;
			ft_clear_line();
			ft_aff_prompt();
		}
		signal(SIGINT, ft_ctrl_c);
	}
	else
		signal(SIGINT, SIG_DFL);
}

static void			ft_quit(int i)
{
	(void)i;
	ft_putchar('\n');
	ft_exit(0);
}

static void			ft_resize(int sig)
{
	struct winsize	w;
	t_ctx			*env;

	(void)sig;
	ioctl(ft_get_fd(), TIOCGWINSZ, &w);
	env = ft_get_ctx();
	env->cols = w.ws_col;
	env->rows = w.ws_row;
}

void				setup_signal(void)
{
	if ((signal(SIGQUIT, ft_quit) == SIG_ERR)
			|| (signal(SIGINT, ft_ctrl_c) == SIG_ERR)
			|| (signal(SIGTSTP, ft_ctrlz) == SIG_ERR)
			|| (signal(SIGCONT, ft_fg) == SIG_ERR)
			|| (signal(SIGCHLD, ft_child) == SIG_ERR)
			|| (signal(SIGWINCH, ft_resize) == SIG_ERR))
		ft_error("failed to setup signals");
}

void				reset_signal(void)
{
	if ((signal(SIGTSTP, SIG_DFL) == SIG_ERR)
			|| (signal(SIGCONT, SIG_DFL) == SIG_ERR)
			|| (signal(SIGINT, SIG_IGN) == SIG_ERR)
			|| (signal(SIGCHLD, SIG_DFL) == SIG_ERR))
		ft_exit(-1);
}
