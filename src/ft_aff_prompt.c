/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/04 13:08:35 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_aff_prompt(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (ctx->prompt)
		return ;
	ft_psone(ctx->env);
	if (PS->str)
		ft_putstr(PS->str);
	else
		ft_putstr("YOLO-Shell> ");
	ctx->prompt = 1;
}
