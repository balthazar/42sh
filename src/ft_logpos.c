/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 23:49:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void			st_clear_bloc(void)
{
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 0), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 1), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 2), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 3), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 4), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 5), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 6), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 11, 7), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
}

static void			st_log(t_pos *pos, t_ctx *ctx)
{
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 0), 1, ft_putput);
	tputs("| W ", 1, ft_putput);
	tputs(ft_itoa(CTX->cols), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 1), 1, ft_putput);
	tputs("| H ", 1, ft_putput);
	tputs(ft_itoa(CTX->rows), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 2), 1, ft_putput);
	tputs("| x ", 1, ft_putput);
	tputs(ft_itoa(pos->x), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 3), 1, ft_putput);
	tputs("| y ", 1, ft_putput);
	tputs(ft_itoa(pos->y), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 4), 1, ft_putput);
	tputs("| i ", 1, ft_putput);
	tputs(ft_itoa(CTX->i), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 5), 1, ft_putput);
	tputs("| L ", 1, ft_putput);
	tputs(ft_itoa(CTX->len), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 6), 1, ft_putput);
	tputs("| X ", 1, ft_putput);
	tputs(ft_itoa((int) ft_strlen(PS->str) + ctx->len), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 7), 1, ft_putput);
	tputs("+--------", 1, ft_putput);
}

void				ft_logpos(void)
{
	t_pos			*pos;

	tputs(tgetstr("sc", NULL), 1, ft_putput);
	pos = &CTX->pos;
	st_clear_bloc();
	st_log(pos, CTX);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
