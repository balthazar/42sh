/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <fbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:09:26 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/10 18:51:21 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include "42sh.h"

void				ft_ctrlz(int sig)
{
	(void)sig;
	if (CTX->sub_proc)
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

static void			ft_ctrl_c(int i)
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

static void			ft_quit(int i)
{
	(void)i;
	ft_putchar('\n');
	ft_exit(0);
}

static void			ft_resize(int sig)
{
	struct winsize	w;
	t_ctx			*ctx;
	int				i;

	(void)sig;
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	ioctl(ft_get_fd(), TIOCGWINSZ, &w);
	ctx = ft_get_ctx();
	ctx->cols = w.ws_col;
	ctx->rows = w.ws_row;
	tputs(tgetstr("cl", NULL), 1, ft_putput);
	ctx->prompt = 0;
	i = ctx->i;
	ft_aff_prompt();
	ctx->i = 0;
	ft_rewrite(TRUE);
	ft_move_to(i);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}

void				setup_signal(void)
{
	if ((signal(SIGQUIT, ft_quit) == SIG_ERR)
			|| (signal(SIGINT, ft_ctrl_c) == SIG_ERR)
			|| (signal(SIGTSTP, ft_ctrlz) == SIG_ERR)
			|| (signal(SIGCONT, ft_fg) == SIG_ERR)
			|| (signal(SIGCHLD, ft_child) == SIG_ERR)
			|| (signal(SIGSEGV, ft_quit) == SIG_ERR)
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
