/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/18 15:56:15 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "42sh.h"

static void			st_close_fd(int fd)
{
	if (fd != -1)
	{
		if (-1 == close(fd))
			ft_error("Can't close file descriptor.");
	}
}

int					ft_close_files(t_btree *node)
{
	st_close_fd(C(node)->fd_in);
	st_close_fd(C(node)->fd_out);
	dup2(ft_get_fd(), 1);
	dup2(ft_get_fd(), 0);
	return (OK);
}
