/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 18:07:15 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/10 18:22:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int					treat_key_home(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	while (ctx->i)
		treat_key_left();
	return (OK);
}
