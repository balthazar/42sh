/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 22:44:18 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void			st_log(int line, char *name, char *str)
{
	char			*tmp;

	tputs(tgoto(tgetstr("cm", NULL), 0, line), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	tmp = ft_strjoin(name, " ");
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(" ", 1, ft_putput);
	tputs(ft_rpad(tmp,  12, '.'), 1, ft_putput);
	tputs(" ", 1, ft_putput);
	tputs("[", 1, ft_putput);
	tputs(str, 1, ft_putput);
	tputs("]", 1, ft_putput);
	tputs(" ", 1, ft_putput);
	ft_memdel((void **) &tmp);
}

void				ft_logpos(void)
{
	t_ctx			*ctx;
	int				i;

	tputs(tgetstr("sc", NULL), 1, ft_putput);
	tputs(tgetstr("mr", NULL), 1, ft_putput);
	ctx = CTX;
	i = 0;

	st_log(i++, "ctx->cols", ft_itoa(ctx->cols));
	st_log(i++, "ctx->rows", ft_itoa(ctx->rows));
	st_log(i++, "ctx->line", ctx->line);
	st_log(i++, "ctx->len", ft_itoa(ctx->len));
	st_log(i++, "ctx->i", ft_itoa(ctx->i));
	st_log(i++, "pos.x", ft_itoa(ctx->pos.x));
	st_log(i++, "pos.y", ft_itoa(ctx->pos.y));

	tputs(tgetstr("me", NULL), 1, ft_putput);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
