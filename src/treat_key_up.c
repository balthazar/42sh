/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:01:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 11:21:36 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		treat_key_up(void)
{
	t_ctx	*ctx;
	char	*res;
	int		i;

	ctx = CTX;
	res = ft_get_string(UP);
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
