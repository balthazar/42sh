/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 12:46:38 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		treat_key_up(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (!ctx->history)
		return (1);
	if (!ctx->cur_h)
	{
		if (ctx->line)
		{
			ft_bzero(ctx->save, LINE_LEN);
			ft_strcpy(ctx->save, ctx->line);
		}
		ctx->cur_h = ctx->end_h;
		ft_reset_line(ctx, 1);
	}
	else if (ctx->cur_h->prev)
	{
		ctx->cur_h = ctx->cur_h->prev;
		ft_reset_line(ctx, 1);
	}
	return (OK);
}
