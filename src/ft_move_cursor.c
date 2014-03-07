/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 16:42:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_move_cursor(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	tputs(tgetstr("do", NULL), 1, ft_putput);
	tputs(tgetstr("cr", NULL), 1, ft_putput);
	ctx->pos.x = 0;
	++ctx->pos.y;
}
