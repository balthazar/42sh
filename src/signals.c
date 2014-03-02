/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:09:26 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/02 18:46:18 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "42sh.h"

// TODO Manage SIGSTOP and SIGCONT properly
// TODO NORM : 6 functions

static void			ft_nothing(int sig)
{
	(void)sig;
}

static void			ft_ctrl_c(int i)
{
	(void)i;
	ft_putchar('\n');
	CTX->prompt = 0;
	ft_bzero(CTX->line, LINE_LEN);
	CTX->i = 0;
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
			|| (signal(SIGTSTP, ft_nothing) == SIG_ERR)
			|| (signal(SIGCONT, ft_nothing) == SIG_ERR)
			|| (signal(SIGWINCH, ft_resize) == SIG_ERR))
		ft_error("failed to setup signals");
}

void				reset_signal(void)
{
	if ((signal(SIGTSTP, SIG_DFL) == SIG_ERR)
			|| (signal(SIGCONT, SIG_DFL) == SIG_ERR))
		exit(-1);
}
