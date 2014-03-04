/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:04:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 00:00:16 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static int			st_exceed(t_ctx *ctx)
{
	(void) ctx;
	return (0);
}

void				ft_add_char(char c)
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
	ctx->line[CTX->i] = c;
	++ctx->pos.x;
	++ctx->i;
	++ctx->len;
	if (st_exceed(ctx) > ctx->cols)
		ft_rewrite();
	else
		ft_putchar(c);
}
