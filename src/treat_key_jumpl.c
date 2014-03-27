/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_jumpl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:28:15 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/14 18:36:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int					treat_key_jumpl(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->len > 0)
	{
		if (ctx->i > 0)
			treat_key_left();
		while (ctx->i > 0 && ctx->line[ctx->i] == ' ')
			treat_key_left();
		while (ctx->i > 0 && ctx->line[ctx->i] != ' ')
			treat_key_left();
		if (ctx->i > 0)
			treat_key_right();
	}
	return (OK);
}
