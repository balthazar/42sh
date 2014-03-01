/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:41:53 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/01 18:04:59 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "42sh.h"

static void			st_push(char c)
{
	CTX->line[CTX->i] = c;
	++CTX->i;
	ft_putchar(c);
}

static int			st_isprint(char *buf)
{
	return (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
			&& buf[4] == 0 && buf[5] == 0);
}

void				ft_aff_prompt(void)
{
	ft_putstr("YOLO-Shell> ");
}

void				ft_prompt(void)
{
	char			buf[BUF_LEN + 1];

	ft_bzero(ft_get_ctx()->line, LINE_LEN);
	ft_aff_prompt();
	while (1 && !(buf[0] == 113 && buf[1] == 0))
	{
		ft_bzero(buf, BUF_LEN + 1);
		read(STDIN_FILENO, buf, BUF_LEN);
		if (st_isprint(buf))
			st_push(buf[0]);
		else if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
			ft_launch();
/*		printf("%d %d %d %d %d %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);*/
	}
}
