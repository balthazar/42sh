/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:27:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/10 18:41:35 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int					treat_key_end(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	while (ctx->i < ctx->len)
		treat_key_right();
	return (OK);
}
