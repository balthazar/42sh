/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:14:15 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/11 14:15:53 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "42sh.h"

void				ft_resize(int sig)
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
