/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:19:58 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 11:20:46 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_clean_line(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	while (ctx->i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putput);
		--ctx->i;
	}
	tputs(tgetstr("ce", NULL), 1, ft_putput);
}
