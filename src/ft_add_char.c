/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:04:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/06 00:05:46 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

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
	++ctx->i;
	++ctx->len;
	ft_putchar(c);
	++ctx->pos.x;
	if (ft_exceed())
		ft_rewrite();
	if (ctx->pos.x >= ctx->cols)
		ft_move_cursor();
}
