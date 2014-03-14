/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_jumpr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:27:31 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/14 18:45:49 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int					treat_key_jumpr(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->i < ctx->len - 1)
	{
		while (ctx->i < ctx->len - 1 && ctx->line[ctx->i] != ' ')
			treat_key_right();
		while (ctx->i < ctx->len - 1 && ctx->line[ctx->i] == ' ')
			treat_key_right();
	}
	return (OK);
}
