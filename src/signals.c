/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <fbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 15:09:26 by fbeck             #+#    #+#             */
/*   Updated: 2014/03/11 14:18:22 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "norme42sh.h"

static void			ft_quit(int i)
{
	(void)i;
	ft_putchar('\n');
	ft_exit(0);
}

static void			ft_sigsev(int sig)
{
	(void)sig;
	ft_error("Segfaulting, but quitting properly.");
}

void				setup_signal(void)
{
	if ((signal(SIGQUIT, ft_quit) == SIG_ERR)
			|| (signal(SIGINT, ft_ctrl_c) == SIG_ERR)
			|| (signal(SIGTSTP, ft_ctrlz) == SIG_ERR)
			|| (signal(SIGCONT, ft_fg) == SIG_ERR)
			|| (signal(SIGCHLD, ft_child) == SIG_ERR)
			|| (signal(SIGSEGV, ft_sigsev) == SIG_ERR)
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
