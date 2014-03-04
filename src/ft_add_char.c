/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 17:04:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/04 12:57:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_add_char(char c)
{
	t_ctx			*ctx;
	int				tmp;

	ctx = CTX;
	tmp = ft_strlen(ctx->line);
	while (tmp != ctx->i)
	{
		ctx->line[tmp] = ctx->line[tmp - 1];
		--tmp;
	}
	CTX->line[CTX->i] = c;
	++CTX->i;
	++CTX->len;
}
