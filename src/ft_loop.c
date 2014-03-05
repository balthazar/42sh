/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:41:53 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/05 16:39:03 by mpillet          ###   ########.fr       */
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
	char			*buf;

	buf = CTX->buf;
	ft_logpos();
	while (1)
	{
		ft_bzero(buf, BUF_LEN + 1);
		read(STDIN_FILENO, buf, BUF_LEN);
		if (st_isprint(buf))
			ft_add_char(buf[0]);
		else
			ft_treat_key(buf);
		ft_logpos();
	}
	return (OK);
}
