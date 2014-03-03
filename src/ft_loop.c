/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:41:53 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/03 13:08:39 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "42sh.h"

static int			st_isprint(char *buf)
{
	return (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
			&& buf[4] == 0 && buf[5] == 0);
}

int					ft_loop(void)
{
	t_ctx	*ctx;

	ctx = CTX;
	ft_psone(ctx->env);
	if (PS->str)
		ft_putstr(PS->str);
	else
		ft_putstr("YOLO-Shell> ");
}

void				ft_prompt(void)
{
	char			*buf;

	buf = CTX->buf;
	while (1)
	{
		ft_bzero(buf, BUF_LEN + 1);
		read(STDIN_FILENO, buf, BUF_LEN);
		if (st_isprint(buf))
		{
			ft_add_char(buf[0]);
			ft_putchar(buf[0]);
		}
		else
			ft_treat_key(buf);
	}
}
