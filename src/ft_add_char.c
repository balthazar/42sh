/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:04:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/14 17:55:41 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

void				ft_insert_char(char c)
{
	t_ctx			*ctx;
	int				tmp;

	ctx = CTX;
	tmp = ft_strlen(ctx->line);
	while (tmp != ctx->i)
	{
		ctx->line[tmp] = ctx->line[tmp - 1];
		--tmp;
	}
	ctx->line[ctx->i] = c;
	++ctx->i;
	++ctx->len;
}

void				ft_add_char(char c)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->len + 1 < LINE_LEN)
	{
		ft_insert_char(c);
		ft_putchar(c);
		++ctx->pos.x;
		if (ft_exceed())
			ft_rewrite(FALSE);
		if (ctx->pos.x >= ctx->cols)
			ft_move_cursor();
	}
}
