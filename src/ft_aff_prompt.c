/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/07 17:51:25 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void				ft_aff_prompt(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (ctx->prompt)
		return ;
	PS->str = NULL;
	/*ft_psone(ctx->env);*/
	if (!PS->str)
		PS->str = ft_strdup("YOLO-Shell> ");
	ft_putstr(PS->str);
	tputs(tgetstr("ce", NULL), 1, ft_putput);
	ctx->prompt = 1;
	ctx->pos.x = ft_strlen(PS->str);
	tputs(tgetstr("im", NULL), 1, ft_putput);
}
