/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exceed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:19:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/06 00:06:22 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int					ft_exceed(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	return (ctx->pos.x + ctx->len - ctx->i > ctx->cols);
}
