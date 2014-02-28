/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/01 00:28:32 by mpillet          ###   ########.fr       */
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

static int			st_create_out(t_btree *node)
{
	t_list			*ptr;
	int				chev_type;
	int				fd;

	ptr = C(node)->out;
	while (ptr)
	{
		if (ERR == st_check_redirect_out(CH(ptr)->file))
			return (ERR);
		chev_type = (CH(ptr)->op == OP_S) ? O_TRUNC : O_APPEND;
		fd = open(CH(ptr)->file, O_WRONLY | O_CREAT | chev_type, 0644);
		close(fd);
		ptr = ptr->next;
	}
	return (OK);
}

int					ft_create_files(t_btree *node)
{
	if (C(node)->type != END)
	{
		if (C(node)->type == PIPE)
		{
			ft_create_files(node->left);
			ft_create_files(node->right);
		}
		else if (C(node)->type == CMD)
		{
			if (ERR == st_create_out(node))
				return (ERR);
		}
	}
	return (OK);
}
