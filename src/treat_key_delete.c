/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/14 18:00:05 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme42sh.h"

int				treat_key_delete(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	if (ctx->i < ctx->len)
	{
		tputs(tgetstr("dc", NULL), 1, ft_putput);
		ft_del_char();
		if (ft_exceed())
			ft_rewrite(FALSE);
	}
	return (OK);
}
