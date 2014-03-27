/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:07:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/27 10:40:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "norme42sh.h"

static void			st_set_defaults(t_ctx *ctx)
{
	struct winsize	w;

	ioctl(ft_get_fd(), TIOCGWINSZ, &w);
	ctx->cols = w.ws_col;
	ctx->rows = w.ws_row;
	ctx->env = NULL;
	ctx->prompt = 0;
	ctx->len = 0;
	ctx->history = NULL;
	ctx->cur_h = NULL;
	ctx->end_h = NULL;
	ctx->jobs = NULL;
	ctx->sub_proc = 0;
	ctx->cpt_h = 0;
	ctx->prompt_len = 0;
	ft_bzero(ctx->line, LINE_LEN);
	ft_bzero(ctx->buf, BUF_LEN);
	PS->str = NULL;
}

t_ctx				*ft_get_ctx(void)
{
	static t_ctx	*ctx = NULL;

	if (!ctx)
	{
		if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
			ft_error("Can't malloc 'ctx'");
		if (!(ctx->psone = (t_psone *)malloc(sizeof(t_psone))))
			ft_error("Can't malloc 'PS1 utility'");
		st_set_defaults(ctx);
	}
	return (ctx);
}
