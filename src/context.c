/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:07:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/04 13:11:16 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdlib.h>
#include "42sh.h"

static void			st_set_defaults(t_ctx *ctx)
{
	struct winsize	w;

	ioctl(ft_get_fd(), TIOCGWINSZ, &w);
	ctx->cols = w.ws_col;
	ctx->rows = w.ws_row;
	ctx->env = NULL;
	ctx->i = 0;
	ctx->prompt = 0;
	ctx->len = 0;
	ctx->history = NULL;
	ctx->cur_h = NULL;
	ctx->end_h = NULL;
	ctx->child = -1;
	ft_bzero(ctx->line, LINE_LEN);
	ft_bzero(ctx->buf, BUF_LEN);
}

t_ctx				*ft_get_ctx(void)
{
	static t_ctx	*ctx = NULL;

	if (!ctx)
	{
		if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
			ft_error("Can't malloc 'ctx'");
		st_set_defaults(ctx);
	}
	return (ctx);
}
