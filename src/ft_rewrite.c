/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/06 19:00:09 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

static void			st_do(t_ctx *ctx, int *i, int *x, int *y)
{
	while (ctx->line[*i])
	{
		if (*x == ctx->cols)
		{
			*x = 0;
			++(*y);
			tputs(tgetstr("do", NULL), 1, ft_putput);
			tputs(tgetstr("cr", NULL), 1, ft_putput);
		}
		ft_putchar(ctx->line[*i]);
		++(*i);
		++(*x);
	}
}

void				ft_rewrite(int hard)
{
	t_ctx			*ctx;
	int				i;
	int				x;
	int				y;

	ctx = CTX;
	if (!hard)
		tputs(tgetstr("sc", NULL), 1, ft_putput);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	if (!hard)
	{
		i = ctx->i;
		x = ctx->pos.x;
		y = ctx->pos.y;
		st_do(ctx, &i, &x, &y);
	}
	else
		st_do(ctx, &ctx->i, &ctx->pos.x, &ctx->pos.y);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
	if (!hard)
		tputs(tgetstr("rc", NULL), 1, ft_putput);
}
