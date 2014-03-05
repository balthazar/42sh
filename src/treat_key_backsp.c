/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_backsp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 19:22:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void			st_go_end(int cols)
{
	int				i;

	i = 0;
	while (i < cols)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putput);
		++i;
	}
}

int					treat_key_backsp(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putput);
		tputs(tgetstr("dc", NULL), 1, ft_putput);
		--ctx->i;
		--ctx->pos.x;
		ft_del_char();
		if (ctx->pos.x < 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putput);
			st_go_end(ctx->cols);
			tputs(tgetstr("le", NULL), 1, ft_putput);
			tputs(tgetstr("dc", NULL), 1, ft_putput);
			tputs(tgetstr("nd", NULL), 1, ft_putput);
			ctx->pos.x = ctx->cols - 1;
			--ctx->pos.y;
		}
		if (ft_exceed())
			ft_rewrite();
	}
	return (OK);
}
