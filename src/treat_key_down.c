/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:45 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 12:47:21 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int		treat_key_down(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (!ctx->history || !ctx->cur_h)
		return (1);
	if (ctx->cur_h->next)
	{
		ctx->cur_h = ctx->cur_h->next;
		ft_reset_line(ctx, 1);
	}
	else if (ctx->save)
	{
		ctx->cur_h = NULL;
		ft_reset_line(ctx, 2);
		ft_bzero(ctx->save, LINE_LEN);
	}
	else if (ctx->line)
	{
		ctx->cur_h = NULL;
		ft_clean_line();
		ft_bzero(ctx->line, LINE_LEN);
	}
	return (OK);
}
