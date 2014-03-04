/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:45 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 11:20:53 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		treat_key_down(void)
{
	t_ctx	*ctx;
	char	*res;
	int		i;

	ctx = CTX;
	res = ft_get_string(DOWN);
	if (res)
	{
		i = 0;
		ft_clean_line();
		ft_bzero(ctx->line, LINE_LEN);
		while (res[i] != '\0')
		{
			ctx->line[i] = res[i];
			++i;
		}
		ctx->i = i;
		ctx->len = i;
		ft_putstr(res);
	}
	return (OK);
}
