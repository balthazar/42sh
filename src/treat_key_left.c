/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:07:52 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/06 18:42:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					treat_key_left(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->i > 0)
	{
		if (ctx->pos.x == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putput);
			ft_go_end(ctx->cols);
			ctx->pos.x = ctx->cols - 1;
			--ctx->pos.y;
		}
		else
		{
			tputs(tgetstr("le", NULL), 1, ft_putput);
			--ctx->pos.x;
		}
		--ctx->i;
	}
	return (OK);
}
