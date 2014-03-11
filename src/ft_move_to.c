/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:08:51 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/07 15:31:23 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

static void			st_go_to(t_ctx *ctx, int pos)
{
	(void) ctx;
	(void) pos;
}

static void			st_back_to(t_ctx *ctx, int pos)
{
	(void) ctx;
	(void) pos;
	while (ctx->i > pos)
	{
		--ctx->pos.x;
		--ctx->i;
		if (ctx->pos.x < 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putput);
			ft_go_end(ctx->cols);
			ctx->pos.x = ctx->cols - 1;
			--ctx->pos.y;
		}
		else
			tputs(tgetstr("le", NULL), 1, ft_putput);
	}
}

void				ft_move_to(int pos)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->i > pos)
		st_back_to(ctx, pos);
	else if (ctx->i < pos)
		st_go_to(ctx, pos);
}
