/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/05 17:11:40 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_del_char(void)
{
	t_ctx			*ctx;
	int				tmp;

	ctx = CTX;
	tmp = ctx->i;
	while (ctx->line[tmp])
	{
		ctx->line[tmp] = ctx->line[tmp + 1];
		++tmp;
	}
	--ctx->len;
}
