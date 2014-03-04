/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 21:57:20 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_logpos(void)
{
	t_pos			*pos;

	pos = &CTX->pos;
	tputs(tgetstr("sc", NULL), 1, ft_putput);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgoto(tgetstr("cm", NULL), CTX->cols - 14, 0), 1, ft_putput);
	tputs("x [", 1, ft_putput);
	tputs(ft_itoa(pos->x), 1, ft_putput);
	tputs("] y [", 1, ft_putput);
	tputs(ft_itoa(pos->y), 1, ft_putput);
	tputs("]", 1, ft_putput);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
