/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/11 15:06:18 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

void				ft_aff_prompt(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (ctx->prompt)
		return ;
	ctx->sub_shell = 0;
	ft_psone(ctx->env, CTX);
	ft_putstr(PS->str);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	ctx->prompt = 1;
	ctx->pos.x = PS->realsize;
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
