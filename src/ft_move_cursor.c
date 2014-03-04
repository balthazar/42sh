/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 22:53:05 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_move_cursor(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->pos.x > ctx->cols - 1)
	{
		tputs(tgetstr("do", NULL), 1, ft_putput);
		tputs(tgetstr("cr", NULL), 1, ft_putput);
		ctx->pos.x = 0;
		++ctx->pos.y;
	}
}
