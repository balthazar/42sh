/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 19:11:40 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_rewrite(void)
{
	t_ctx			*ctx;
	int				i;

	ctx = CTX;
	tputs(tgetstr("sc", NULL), 1, ft_putput);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	i = ctx->i;
	while (ctx->line[i])
	{
		ft_putchar(ctx->line[i]);
		++i;
	}
	ft_putchar(' ');
	tputs(tgetstr("im", NULL), 1, ft_putput);
	tputs(tgetstr("rc", NULL), 1, ft_putput);
	ft_logpos();
}
