/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:43:27 by fbeck             #+#    #+#             */
/*   Updated: 2014/02/28 17:00:51 by fbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "42sh.h"

static int			st_check_redirect_out(char *file)
{
	if (access(file, F_OK) > -1)
	{
		if (access(file, W_OK) > -1)
			return (OK);
		ft_putendl_fd("Error: Permission denied", 2);
		return (ERR);
	}
	return (OK);
}

static int			st_check_redirect_in(char *file)
{
	if (access(file, F_OK) > -1)
	{
		if (access(file, R_OK) > -1)
			return (OK);
		ft_putendl_fd("Error: Permission denied", 2);
		return (ERR);
	}
	ft_putendl_fd("Error: no such file or directory", 2);
	return (ERR);
}

static int			st_dup_fd_out(t_btree *node)
{
	t_list			*ptr;
	int				fd;
	int				chev_type;

	ptr = C(node)->out;
	while (ptr)
	{
		if (ERR == st_check_redirect_out(CH(ptr)->file))
			return (ERR);
		chev_type = (CH(ptr)->op == OP_S) ? O_TRUNC : O_APPEND;
		fd = open(CH(ptr)->file, O_WRONLY | O_CREAT | chev_type, 0644);
		if (ptr->next == NULL)
			dup2(fd, 1);
		else
			close(fd);
		ptr = ptr->next;
	}
	return (OK);
}

int					ft_redirect(t_btree *node)
{
	t_list			*ptr;
	int				fd;

	ptr = C(node)->in;
	while (ptr)
	{
		if (ERR == st_check_redirect_in(CH(ptr)->file))
			return (ERR);
		fd = open(CH(ptr)->file, O_RDONLY);
		if (ptr->next == NULL)
			dup2(fd, 0);
		else
			close(fd);
		ptr = ptr->next;
	}
	if (ERR == st_dup_fd_out(node))
		return (ERR);
	return (OK);
}
