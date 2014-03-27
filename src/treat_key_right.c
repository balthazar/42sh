/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:12:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 16:51:55 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int					treat_key_right(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->i < ctx->len)
	{
		++ctx->i;
		++ctx->pos.x;
		if (ctx->pos.x >= ctx->cols)
			ft_move_cursor();
		else
			tputs(tgetstr("nd", NULL), 1, ft_putput);
	}
	return (OK);
}
