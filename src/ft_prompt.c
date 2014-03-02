/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janteuni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:41:53 by janteuni          #+#    #+#             */
/*   Updated: 2014/03/02 18:34:10 by fbeck            ###   ########.fr       */
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

void				ft_aff_prompt(void)
{
	if (CTX->prompt)
		return ;
	ft_putstr("YOLO-Shell> ");
	CTX->prompt = 1;

}

void				ft_prompt(void)
{
	char			buf[BUF_LEN + 1];

	ft_bzero(ft_get_ctx()->line, LINE_LEN);
	ft_aff_prompt();
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
		/*				printf("%d %d %d %d %d %d\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5]);*/
	}
}
