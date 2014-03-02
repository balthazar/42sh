/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:41:53 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/02 15:51:40 by mpillet          ###   ########.fr       */
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

static int			is_full_cmd(char *line)
{
	int				i;

	i = ft_strlen(line) - 1;
	while (i > 1 && line[i] == ' ')
		--i;
	return (!(line[i] == '&' && line[i - 1] == '&')
			&& !(line[i] == '|') && ft_odd_quotes(line));
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
		{
			st_push(buf[0]);
			ft_putchar(buf[0]);
		}
		else if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
		{
			if (is_full_cmd(CTX->line))
			{
				// TODO sauvegarder CTX->line dans histo
				ft_launch();
			}
			else if (ft_is_valid(CTX->line))
			{
				if (!ft_odd_quotes(CTX->line))
					st_push('\n');
				ft_putstr("> ");
			}
			else
			{
				// TODO sauvegarder CTX->line dans histo
				ft_bzero(CTX->line, LINE_LEN);
				CTX->i = 0;
				ft_aff_prompt();
			}
		}
		/*		printf("%d %d %d %d %d %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);*/
	}
}
