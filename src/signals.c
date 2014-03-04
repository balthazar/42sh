/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:09:26 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/04 12:46:55 by janteuni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void				print_toto(void)
{
	t_list			*list;

	list = CTX->jobs;
	while (list)
	{
		printf("----------------------------------------\n");
		printf("PID [%d]\n", ((t_jobs *)list->content)->pid);
		printf("First or not  [%d]\n", ((t_jobs *)list->content)->first);
		printf("NB [%d]\n", ((t_jobs *)list->content)->nb);
		printf("----------------------------------------\n");
		list = list->next;
	}
}

void				ft_ctrlz(int sig)
{
	(void)sig;
	if (CTX->jobs)
	{
		signal(SIGTSTP, SIG_DFL);
		if (kill(((t_jobs *)CTX->jobs->content)->pid, SIGTSTP) != -1)
		{
			ft_putendl("[1]+  Stopped(SIGTSTP)\n");
			CTX->prompt = 0;
			ft_clear_line();
			ft_aff_prompt();
		}
		signal(SIGTSTP, ft_ctrlz);
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
			/*DELETE element de la liste*/
			ft_putendl("fg: current: no such job");
		}
	}
	else
		ft_putendl("fg: current: no such job");
}

static void			ft_ctrl_c(int i)
{
	(void)i;
	ft_putchar('\n');
	CTX->prompt = 0;
	ft_clear_line();
	ft_aff_prompt();
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
			|| (signal(SIGWINCH, ft_resize) == SIG_ERR))
		ft_error("failed to setup signals");
}

void				reset_signal(void)
{
	if ((signal(SIGTSTP, SIG_DFL) == SIG_ERR)
			|| (signal(SIGCONT, SIG_DFL) == SIG_ERR))
		exit(-1);
}
