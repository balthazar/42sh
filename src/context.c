/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:07:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/01 18:23:22 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

t_ctx				*ft_get_ctx(void)
{
	static t_ctx	*ctx = NULL;
	struct winsize	w;


	if (NULL == ctx)
	{
		if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
			ft_error("Can't malloc 'ctx'");
		ioctl(get_fd(), TIOCGWINSZ, &w);
		ctx->cols = w.ws_col;
		ctx->rows = w.ws_row;
		ctx->env = NULL;
	}
	return (ctx);
}
