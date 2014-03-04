/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 22:21:42 by mpillet          ###   ########.fr       */
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
}

static void			st_log(t_pos *pos)
{
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 0), 1, ft_putput);
	tputs("| x [", 1, ft_putput);
	tputs(ft_itoa(pos->x), 1, ft_putput);
	tputs("]", 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 1), 1, ft_putput);
	tputs("| y [", 1, ft_putput);
	tputs(ft_itoa(pos->y), 1, ft_putput);
	tputs("]", 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 2), 1, ft_putput);
	tputs("| i [", 1, ft_putput);
	tputs(ft_itoa(CTX->i), 1, ft_putput);
	tputs("]", 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 9, 3), 1, ft_putput);
	tputs("+--------", 1, ft_putput);
}

void				ft_logpos(void)
{
	t_pos			*pos;

	tputs(tgetstr("sc", NULL), 1, ft_putput);
	pos = &CTX->pos;
	st_clear_bloc();
	st_log(pos);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
