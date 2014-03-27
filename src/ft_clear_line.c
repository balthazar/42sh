/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:27:43 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/04 21:10:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

void				ft_clear_line(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	ft_bzero(ctx->line, LINE_LEN);
	ctx->i = 0;
	ctx->len = 0;
	ctx->pos.x = 0;
	ctx->pos.y = 0;
}
