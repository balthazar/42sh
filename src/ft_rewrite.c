/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/06 00:20:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_rewrite(void)
{
	t_ctx			*ctx;
	int				i;
	int				x;
	int				y;

	ctx = CTX;
	tputs(tgetstr("sc", NULL), 1, ft_putput);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	i = ctx->i;
	x = ctx->pos.x;
	y = ctx->pos.y;
	while (ctx->line[i])
	{
		if (x == ctx->cols)
		{
			x = 0;
			++y;
			tputs(tgetstr("do", NULL), 1, ft_putput);
			tputs(tgetstr("cr", NULL), 1, ft_putput);
		}
		ft_putchar(ctx->line[i]);
		++i;
		++x;
	}
	ft_putchar(' ');
	tputs(tgetstr("im", NULL), 1, ft_putput);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	ft_logpos();
}
