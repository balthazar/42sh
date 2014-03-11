/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:19:58 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/06 18:50:25 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_clean_line(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	while (ctx->i > 0)
	{
		if (ctx->pos.x == 0)
		{
			tputs(tgetstr("ce", NULL), 1, ft_putput);
			tputs(tgetstr("up", NULL), 1, ft_putput);
			ft_go_end(ctx->cols);
			ctx->pos.x = ctx->cols;
			--ctx->pos.y;
		}
		else
			tputs(tgetstr("le", NULL), 1, ft_putput);
		--ctx->i;
		--ctx->pos.x;
	}
	ctx->len = 0;
	tputs(tgetstr("ce", NULL), 1, ft_putput);
}
