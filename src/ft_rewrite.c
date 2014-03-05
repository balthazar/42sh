/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 17:15:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static int			st_exceed(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	return (ctx->pos.x + ctx->len - ctx->i > ctx->cols);
}

void				ft_rewrite(void)
{
	ft_putstr("rewriting");
}
