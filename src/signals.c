/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:09:26 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/01 18:23:26 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "42sh.h"

static void			ft_nothing(int sig)
{
	(void)sig;
}

static void			ft_ctrl_c(int i)
{
	(void)i;
	ft_putchar('\n');
	/* DISPLAY PROMPT */
}

static void			ft_ctrl_d(int i)
{
	(void)i;
	ft_putchar('\n');
	/* CLOSE TERM */
	exit (0);
}

static void			ft_resize(int sig)
{
	struct winsize	w;
	t_ctx			*env;

	ioctl(get_fd(), TIOCGWINSZ, &w);
	env = ft_get_ctx();
	env->cols = w.ws_col;
	env->rows = w.ws_row;
	/* DISPLAY */
}

void				setup_signal(void)
{
	if ((signal(SIGQUIT, ft_ctrl_d) == SIG_ERR)
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
